#include <iostream>
#include <string>

using namespace std;

class Intersection
{
public:
    int intersectionID;
    string currentLight; // Red, Yellow, Green
    int redDuration;
    int yellowDuration;
    int greenDuration;
    int remainingTime;
    string trafficLoad; // low, medium, high
    bool priorityMode;
    Intersection *next;
    Intersection *prev;

    Intersection(int id, string load)
    {
        intersectionID = id;
        trafficLoad = load;
        currentLight = "Red";
        priorityMode = false;
        if (trafficLoad == "high")
        {
            redDuration = 60;
            greenDuration = 60;
            yellowDuration = 5;
        }
        else if (trafficLoad == "medium")
        {
            redDuration = 45;
            greenDuration = 45;
            yellowDuration = 5;
        }
        else
        {
            redDuration = 30;
            greenDuration = 30;
            yellowDuration = 5;
        }
        remainingTime = redDuration;
        next = prev = nullptr;
    }

    void setPriorityMode(bool isPriority)
    {
        priorityMode = isPriority;
        if (priorityMode)
        {
            greenDuration *= 2; // Double green duration for priority mode
        }
    }
};

class TrafficLightSystem
{
private:
    Intersection *head;
    int numIntersections;

public:
    TrafficLightSystem() : head(nullptr), numIntersections(0) {}

    void addIntersection(int id, string trafficLoad)
    {
        Intersection *newIntersection = new Intersection(id, trafficLoad);
        if (!head)
        {
            head = newIntersection;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Intersection *tail = head->prev;
            tail->next = newIntersection;
            newIntersection->prev = tail;
            newIntersection->next = head;
            head->prev = newIntersection;
        }
        numIntersections++;
        cout << "Intersection " << id << " added with traffic load: " << trafficLoad << ".\n";
    }

    void simulateTrafficLightChanges()
    {
        if (!head)
        {
            cout << "No intersections in the system.\n";
            return;
        }

        Intersection *current = head;
        do
        {
            cout << "Intersection " << current->intersectionID << " - Current Light: " << current->currentLight
                << " | Remaining Time: " << current->remainingTime << " seconds.\n";

            current->remainingTime--;
            if (current->remainingTime == 0)
            {
                if (current->currentLight == "Red")
                {
                    current->currentLight = "Green";
                    current->remainingTime = current->greenDuration;
                }
                else if (current->currentLight == "Green")
                {
                    current->currentLight = "Yellow";
                    current->remainingTime = current->yellowDuration;
                }
                else if (current->currentLight == "Yellow")
                {
                    current->currentLight = "Red";
                    current->remainingTime = current->redDuration;
                }
            }
            current = current->next;
        } while (current != head);
    }

    void adjustTrafficLightDuration(int id, string newTrafficLoad)
    {
        Intersection *current = head;
        do
        {
            if (current->intersectionID == id)
            {
                current->trafficLoad = newTrafficLoad;
                if (newTrafficLoad == "high")
                {
                    current->redDuration = 60;
                    current->greenDuration = 60;
                }
                else if (newTrafficLoad == "medium")
                {
                    current->redDuration = 45;
                    current->greenDuration = 45;
                }
                else
                {
                    current->redDuration = 30;
                    current->greenDuration = 30;
                }
                current->yellowDuration = 5;
                cout << "Intersection " << id << " updated with new traffic load: " << newTrafficLoad << ".\n";
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Intersection " << id << " not found.\n";
    }

    void displayTrafficStatus()
    {
        if (!head)
        {
            cout << "No intersections in the system.\n";
            return;
        }

        Intersection *current = head;
        do
        {
            cout << "Intersection " << current->intersectionID << " - Current Light: " << current->currentLight << " | Remaining Time: " << current->remainingTime << " seconds.\n";
            current = current->next;
        } while (current != head);
    }

    void setPriorityIntersection(int id)
    {
        Intersection *current = head;
        do
        {
            if (current->intersectionID == id)
            {
                current->setPriorityMode(true);
                cout << "Intersection " << id << " set to priority mode.\n";
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Intersection " << id << " not found.\n";
    }

    void trafficLoadBalancing()
    {
        if (!head)
            return;

        Intersection *current = head;
        do
        {
            if (current->currentLight == "Red" && current->remainingTime > 90)
            {
                Intersection *temp = current->next;
                while (temp != current)
                {
                    if (temp->currentLight == "Green" && temp->greenDuration > 20)
                    {
                        temp->greenDuration -= 10;
                        cout << "Reduced green time at Intersection " << temp->intersectionID << " to balance traffic.\n";
                    }
                    temp = temp->next;
                }
                break;
            }
            current = current->next;
        } while (current != head);
    }
};

int main()
{
    TrafficLightSystem system;
    int choice, id;
    string trafficLoad;

    do
    {
        cout << "\nTraffic Light Management System\n";
        cout << "1. Add Intersection\n";
        cout << "2. Simulate Traffic Light Changes\n";
        cout << "3. Adjust Traffic Light Duration\n";
        cout << "4. Display Traffic Status\n";
        cout << "5. Set Priority Intersection\n";
        cout << "6. Balance Traffic Load\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Intersection ID: ";
            cin >> id;
            cout << "Enter Traffic Load (low/medium/high): ";
            cin >> trafficLoad;
            system.addIntersection(id, trafficLoad);
            break;

        case 2:
            system.simulateTrafficLightChanges();
            break;

        case 3:
            cout << "Enter Intersection ID: ";
            cin >> id;
            cout << "Enter New Traffic Load (low/medium/high): ";
            cin >> trafficLoad;
            system.adjustTrafficLightDuration(id, trafficLoad);
            break;

        case 4:
            system.displayTrafficStatus();
            break;

        case 5:
            cout << "Enter Intersection ID for Priority: ";
            cin >> id;
            system.setPriorityIntersection(id);
            break;

        case 6:
            system.trafficLoadBalancing();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
