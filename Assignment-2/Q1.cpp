#include <iostream>
#include <string>

using namespace std;

const int MAX_PARTICIPANTS = 3;

// Participant class definition
class Participant
{
public:
    int registrationID;
    string name;
    string email;
    string status; // "Registered" or "Waiting"
    Participant *next;

    // Constructor
    Participant(int regID, const string &name, const string &email, const string &status)
        : registrationID(regID), name(name), email(email), status(status), next(nullptr) {}
};

class EventManagementSystem
{
private:
    Participant *registeredList;
    Participant *waitingList;
    int registeredCount;

public:
    EventManagementSystem() : registeredList(nullptr), waitingList(nullptr), registeredCount(0) {}

    void registerParticipant(int regID, const string &name, const string &email)
    {
        Participant *newParticipant = new Participant(regID, name, email, "");

        if (registeredCount < MAX_PARTICIPANTS)
        {
            newParticipant->status = "Registered";
            newParticipant->next = registeredList;
            registeredList = newParticipant;
            registeredCount++;
            cout << "Participant " << name << " has been registered successfully." << endl;
        }
        
        else
        {
            newParticipant->status = "Waiting";
            newParticipant->next = waitingList;
            waitingList = newParticipant;
            cout << "Event is fully booked. " << name << " has been added to the waiting list." << endl;
        }
    }

    void cancelRegistration(int regID)
    {
        if (registeredList == nullptr)
        {
            cout << "No participants registered." << endl;
            return;
        }

        Participant *current = registeredList;
        Participant *previous = nullptr;

        // Find the participant in the registered list
        while (current != nullptr && current->registrationID != regID)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Registration ID not found." << endl;
            return;
        }

        // Remove participant from the registered list
        if (previous == nullptr)
        {
            registeredList = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
        registeredCount--;

        // Move the first person from the waiting list to the registered list
        if (waitingList != nullptr)
        {
            Participant *temp = waitingList;
            waitingList = waitingList->next;

            temp->status = "Registered";
            temp->next = registeredList;
            registeredList = temp;
            registeredCount++;

            cout << "Participant from the waiting list has been moved to the registered list." << endl;
        }

        cout << "Registration canceled." << endl;
    }

    void displayRegisteredParticipants()
    {
        if (registeredList == nullptr)
        {
            cout << "No participants registered." << endl;
            return;
        }

        Participant *current = registeredList;
        cout << "Registered Participants:" << endl;
        while (current != nullptr)
        {
            cout << "ID: " << current->registrationID << ", Name: " << current->name
                 << ", Email: " << current->email << ", Status: " << current->status << endl;
            current = current->next;
        }
    }

    void displayWaitingList()
    {
        if (waitingList == nullptr)
        {
            cout << "No participants in the waiting list." << endl;
            return;
        }

        Participant *current = waitingList;
        cout << "Waiting List Participants:" << endl;
        while (current != nullptr)
        {
            cout << "ID: " << current->registrationID << ", Name: " << current->name
                 << ", Email: " << current->email << ", Status: " << current->status << endl;
            current = current->next;
        }
    }

    void searchByEmail(const string &email)
    {
        Participant *current = registeredList;

        // Search in registered list
        while (current != nullptr)
        {
            if (current->email == email)
            {
                cout << "Participant found: Registered - Name: " << current->name << ", Email: " << current->email << endl;
                return;
            }
            current = current->next;
        }

        // Search in waiting list
        current = waitingList;
        while (current != nullptr)
        {
            if (current->email == email)
            {
                cout << "Participant found: Waiting - Name: " << current->name << ", Email: " << current->email << endl;
                return;
            }
            current = current->next;
        }

        cout << "Participant with email " << email << " not found." << endl;
    }
};

int main()
{
    EventManagementSystem system;
    int choice, regID;
    string name, email;

    do
    {
        cout << "\nEvent Management System" << endl;
        cout << "1. Register Participant" << endl;
        cout << "2. Cancel Registration" << endl;
        cout << "3. Display Registered Participants" << endl;
        cout << "4. Display Waiting List" << endl;
        cout << "5. Search by Email" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Registration ID: ";
            cin >> regID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Email: ";
            cin >> email;
            system.registerParticipant(regID, name, email);
            break;
        case 2:
            cout << "Enter Registration ID to cancel: ";
            cin >> regID;
            system.cancelRegistration(regID);
            break;
        case 3:
            system.displayRegisteredParticipants();
            break;
        case 4:
            system.displayWaitingList();
            break;
        case 5:
            cout << "Enter Email to search: ";
            cin >> email;
            system.searchByEmail(email);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
