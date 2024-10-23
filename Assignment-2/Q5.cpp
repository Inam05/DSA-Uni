#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Train
{
public:
    int trainNumber;
    string departureTime;
    string arrivalTime;
    string route;
    string status;
    Train *next;
    Train *prev;

    Train(int num, string depTime, string arrTime, string rt)
        : trainNumber(num), departureTime(depTime), arrivalTime(arrTime),
          route(rt), status("On Time"), next(nullptr), prev(nullptr) {}
};

class Schedule
{
private:
    Train *head;
    Train *tail;

    bool isTimeEarlier(string time1, string time2)
    {
        int hour1 = stoi(time1.substr(0, 2));
        int min1 = stoi(time1.substr(3, 2));
        int hour2 = stoi(time2.substr(0, 2));
        int min2 = stoi(time2.substr(3, 2));

        if (hour1 < hour2 || (hour1 == hour2 && min1 < min2))
            return true;
        return false;
    }

public:
    Schedule() : head(nullptr), tail(nullptr) {}

    void addTrain(int number, string depTime, string arrTime, string route)
    {
        Train *newTrain = new Train(number, depTime, arrTime, route);

        if (!head || isTimeEarlier(depTime, head->departureTime))
        {
            newTrain->next = head;
            if (head)
                head->prev = newTrain;
            head = newTrain;
            if (!tail)
                tail = newTrain;
        }
        else
        {
            Train *temp = head;
            while (temp->next && !isTimeEarlier(depTime, temp->next->departureTime))
            {
                temp = temp->next;
            }
            newTrain->next = temp->next;
            if (temp->next)
                temp->next->prev = newTrain;
            temp->next = newTrain;
            newTrain->prev = temp;
            if (!newTrain->next)
                tail = newTrain;
        }
    }

    void updateTrainStatus(int number, string newStatus)
    {
        Train *temp = head;
        while (temp)
        {
            if (temp->trainNumber == number)
            {
                temp->status = newStatus;
                cout << "Train " << number << " status updated to " << newStatus << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Train " << number << " not found.\n";
    }

    void removeTrain(int number)
    {
        Train *temp = head;
        while (temp)
        {
            if (temp->trainNumber == number)
            {
                if (temp->prev)
                    temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;
                delete temp;
                cout << "Train " << number << " removed from schedule.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Train " << number << " not found.\n";
    }

    void findNextTrain(string currentTime)
    {
        Train *temp = head;
        while (temp)
        {
            if (isTimeEarlier(currentTime, temp->departureTime))
            {
                cout << "Next train: " << temp->trainNumber << ", Departure: " << temp->departureTime
                     << ", Arrival: " << temp->arrivalTime << ", Route: " << temp->route
                     << ", Status: " << temp->status << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No upcoming trains.\n";
    }

    void displayTrainsOnRoute(string route)
    {
        Train *temp = head;
        bool found = false;
        while (temp)
        {
            if (temp->route == route)
            {
                found = true;
                cout << "Train " << temp->trainNumber << ": Departure: " << temp->departureTime
                     << ", Arrival: " << temp->arrivalTime << ", Status: " << temp->status << endl;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "No trains found on route " << route << ".\n";
        }
    }

    void reverseTraversal()
    {
        Train *temp = tail;
        while (temp)
        {
            cout << "Train " << temp->trainNumber << ": Departure: " << temp->departureTime
                 << ", Arrival: " << temp->arrivalTime << ", Route: " << temp->route
                 << ", Status: " << temp->status << endl;
            temp = temp->prev;
        }
    }

    void rescheduleTrain(int number, string newDepTime, string newArrTime)
    {
        removeTrain(number);
        addTrain(number, newDepTime, newArrTime, "");
        cout << "Train " << number << " rescheduled.\n";
    }

    void realTimeUpdates(string currentTime)
    {
        Train *temp = head;
        while (temp)
        {
            if (!isTimeEarlier(temp->departureTime, currentTime) && temp->status == "On Time")
            {
                temp->status = "Departed";
                cout << "Train " << temp->trainNumber << " has departed.\n";
            }
            temp = temp->next;
        }
    }
};

int main()
{
    Schedule schedule;
    int choice, number;
    string depTime, arrTime, route, status, currentTime;

    do
    {
        cout << "\nTrain Scheduling System\n";
        cout << "1. Add Train\n";
        cout << "2. Update Train Status\n";
        cout << "3. Remove Train\n";
        cout << "4. Find Next Train to Depart\n";
        cout << "5. Display All Trains on Route\n";
        cout << "6. Reverse Traversal of Departed Trains\n";
        cout << "7. Reschedule Train\n";
        cout << "8. Real-Time Updates\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Train Number: ";
            cin >> number;
            cout << "Enter Departure Time (HH:MM): ";
            cin >> depTime;
            cout << "Enter Arrival Time (HH:MM): ";
            cin >> arrTime;
            cout << "Enter Route (source-destination): ";
            cin.ignore();
            getline(cin, route);
            schedule.addTrain(number, depTime, arrTime, route);
            break;

        case 2:
            cout << "Enter Train Number: ";
            cin >> number;
            cout << "Enter New Status (On Time, Delayed, Cancelled): ";
            cin.ignore();
            getline(cin, status);
            schedule.updateTrainStatus(number, status);
            break;

        case 3:
            cout << "Enter Train Number to Remove: ";
            cin >> number;
            schedule.removeTrain(number);
            break;

        case 4:
            cout << "Enter Current Time (HH:MM): ";
            cin >> currentTime;
            schedule.findNextTrain(currentTime);
            break;

        case 5:
            cout << "Enter Route: ";
            cin.ignore();
            getline(cin, route);
            schedule.displayTrainsOnRoute(route);
            break;

        case 6:
            schedule.reverseTraversal();
            break;

        case 7:
            cout << "Enter Train Number: ";
            cin >> number;
            cout << "Enter New Departure Time (HH:MM): ";
            cin >> depTime;
            cout << "Enter New Arrival Time (HH:MM): ";
            cin >> arrTime;
            schedule.rescheduleTrain(number, depTime, arrTime);
            break;

        case 8:
            cout << "Enter Current Time (HH:MM): ";
            cin >> currentTime;
            schedule.realTimeUpdates(currentTime);
            break;

        case 9:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
