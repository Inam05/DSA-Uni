#include <iostream>
#include <string>

using namespace std;

class Process
{
public:
    int processID;
    string processName;
    int executionTime;
    int remainingTime;
    Process *next;

    Process(int id, string name, int execTime)
    {
        processID = id;
        processName = name;
        executionTime = execTime;
        remainingTime = execTime;
        next = nullptr;
    }
};

class RoundRobinScheduler
{
private:
    Process *head;
    Process *tail;
    int timeQuantum;

public:
    RoundRobinScheduler(int quantum) : head(nullptr), tail(nullptr), timeQuantum(quantum) {}

    void addProcess(int id, string name, int execTime)
    {
        Process *newProcess = new Process(id, name, execTime);
        if (!head)
        {
            head = newProcess;
            tail = newProcess;
            tail->next = head;
        }
        else
        {
            tail->next = newProcess;
            tail = newProcess;
            tail->next = head;
        }
        cout << "Process " << name << " (ID: " << id << ") added to the queue.\n";
    }

    void simulateScheduling()
    {
        if (!head)
        {
            cout << "CPU is idle.\n";
            return;
        }

        Process *current = head;
        do
        {
            cout << "Executing process " << current->processName << " (ID: " << current->processID << ")...\n";
            if (current->remainingTime <= timeQuantum)
            {
                cout << "Process " << current->processName << " completed.\n";
                removeProcess(current->processID);
            }
            else
            {
                current->remainingTime -= timeQuantum;
                cout << "Time quantum used, remaining burst time for " << current->processName << ": " << current->remainingTime << " units.\n";
            }
            current = current->next;
        } while (current != head);
    }

    void displayProcesses()
    {
        if (!head)
        {
            cout << "No active processes.\n";
            return;
        }

        Process *temp = head;
        do
        {
            cout << "Process ID: " << temp->processID << ", Name: " << temp->processName
                 << ", Remaining Burst Time: " << temp->remainingTime << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void removeProcess(int id)
    {
        if (!head)
            return;

        Process *current = head;
        Process *previous = nullptr;

        do
        {
            if (current->processID == id)
            {
                if (current == head && current == tail)
                {
                    head = tail = nullptr;
                }
                else if (current == head)
                {
                    head = head->next;
                    tail->next = head;
                }
                else if (current == tail)
                {
                    previous->next = head;
                    tail = previous;
                }
                else
                {
                    previous->next = current->next;
                }

                delete current;
                cout << "Process ID " << id << " removed from the queue.\n";
                return;
            }

            previous = current;
            current = current->next;
        } while (current != head);
    }

    void processPreemption(int id, string name, int execTime)
    {
        Process *newProcess = new Process(id, name, execTime);
        if (!head)
        {
            head = newProcess;
            tail = newProcess;
            tail->next = head;
            return;
        }

        if (newProcess->processID < head->processID)
        {
            newProcess->next = head;
            head = newProcess;
            tail->next = head;
            cout << "Process " << name << " (ID: " << id << ") preempted and inserted at the front of the queue.\n";
        }
        else
        {
            addProcess(id, name, execTime);
        }
    }
};

int main()
{
    int quantum = 4; // Example time quantum
    RoundRobinScheduler scheduler(quantum);

    int choice;
    int id;
    string name;
    int execTime;

    do
    {
        cout << "\nCPU Round-Robin Scheduling\n";
        cout << "1. Add Process\n";
        cout << "2. Simulate Round-Robin Scheduling\n";
        cout << "3. Display Processes\n";
        cout << "4. Preempt Process\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Process ID: ";
            cin >> id;
            cout << "Enter Process Name: ";
            cin >> name;
            cout << "Enter Execution Time: ";
            cin >> execTime;
            scheduler.addProcess(id, name, execTime);
            break;

        case 2:
            scheduler.simulateScheduling();
            break;

        case 3:
            scheduler.displayProcesses();
            break;

        case 4:
            cout << "Enter Process ID: ";
            cin >> id;
            cout << "Enter Process Name: ";
            cin >> name;
            cout << "Enter Execution Time: ";
            cin >> execTime;
            scheduler.processPreemption(id, name, execTime);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
