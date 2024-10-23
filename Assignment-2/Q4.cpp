#include <iostream>
#include <string>

using namespace std;

class Task
{
public:
    int taskID;
    string taskName;
    string taskDescription;
    string taskStatus;
    int dependencies[10];
    int numDependencies;
    Task *next;
    Task *prev;

    Task(int id, string name, string desc)
        : taskID(id), taskName(name), taskDescription(desc), taskStatus("Pending"),
          next(nullptr), prev(nullptr), numDependencies(0) {}
};

class History
{
public:
    Task *task;
    string action;
    History *next;
    History *prev;

    History(Task *t, string act)
        : task(t), action(act), next(nullptr), prev(nullptr) {}
};

class TaskManager
{
private:
    Task *head;
    Task *tail;
    History *undoStack;
    History *redoStack;

public:
    TaskManager() : head(nullptr), tail(nullptr), undoStack(nullptr), redoStack(nullptr) {}

    void addTask(int id, string name, string desc)
    {
        Task *newTask = new Task(id, name, desc);
        if (!head)
        {
            head = newTask;
            tail = newTask;
        }
        else
        {
            tail->next = newTask;
            newTask->prev = tail;
            tail = newTask;
        }
    }

    void addDependency(int taskID, int dependencyID)
    {
        Task *task = findTask(taskID);
        if (task)
        {
            task->dependencies[task->numDependencies++] = dependencyID;
        }
    }

    Task *findTask(int id)
    {
        Task *temp = head;
        while (temp)
        {
            if (temp->taskID == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    bool canCompleteTask(Task *task)
    {
        for (int i = 0; i < task->numDependencies; i++)
        {
            Task *dependency = findTask(task->dependencies[i]);
            if (dependency && dependency->taskStatus != "Completed")
            {
                return false;
            }
        }
        return true;
    }

    void markTaskCompleted(int id)
    {
        Task *task = findTask(id);
        if (task && canCompleteTask(task))
        {
            task->taskStatus = "Completed";
            addToUndoStack(task, "Complete");
            cout << "Task " << task->taskName << " marked as completed.\n";
        }
        else
        {
            cout << "Task cannot be completed. Check dependencies.\n";
        }
    }

    void addToUndoStack(Task *task, string action)
    {
        History *newHistory = new History(task, action);
        if (!undoStack)
        {
            undoStack = newHistory;
        }
        else
        {
            undoStack->next = newHistory;
            newHistory->prev = undoStack;
            undoStack = newHistory;
        }
    }

    void addToRedoStack(Task *task, string action)
    {
        History *newHistory = new History(task, action);
        if (!redoStack)
        {
            redoStack = newHistory;
        }
        else
        {
            redoStack->next = newHistory;
            newHistory->prev = redoStack;
            redoStack = newHistory;
        }
    }

    void undoCompletion()
    {
        if (undoStack && undoStack->action == "Complete")
        {
            undoStack->task->taskStatus = "Pending";
            addToRedoStack(undoStack->task, "Complete");
            cout << "Undo: Task " << undoStack->task->taskName << " marked as pending.\n";
            undoStack = undoStack->prev;
        }
        else
        {
            cout << "No task to undo.\n";
        }
    }

    void redoCompletion()
    {
        if (redoStack && redoStack->action == "Complete")
        {
            if (canCompleteTask(redoStack->task))
            {
                redoStack->task->taskStatus = "Completed";
                addToUndoStack(redoStack->task, "Complete");
                cout << "Redo: Task " << redoStack->task->taskName << " marked as completed again.\n";
                redoStack = redoStack->prev;
            }
            else
            {
                cout << "Cannot redo task, dependencies not met.\n";
            }
        }
        else
        {
            cout << "No task to redo.\n";
        }
    }

    void viewTasks()
    {
        Task *temp = head;
        while (temp)
        {
            cout << "Task ID: " << temp->taskID << ", Name: " << temp->taskName
                 << ", Status: " << temp->taskStatus << "\nDependencies: ";
            for (int i = 0; i < temp->numDependencies; i++)
            {
                cout << temp->dependencies[i] << " ";
            }
            cout << endl;
            temp = temp->next;
        }
    }

    void deleteTask(int id)
    {
        Task *task = findTask(id);
        if (!task)
            return;

        if (task->prev)
            task->prev->next = task->next;
        if (task->next)
            task->next->prev = task->prev;
        if (task == head)
            head = task->next;
        if (task == tail)
            tail = task->prev;

        delete task;
        cout << "Task deleted.\n";
    }
};

int main()
{
    TaskManager manager;
    int choice, id, depID;
    string name, desc;

    do
    {
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n";
        cout << "2. Add Dependency\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Undo Last Completion\n";
        cout << "5. Redo Last Completion\n";
        cout << "6. View All Tasks\n";
        cout << "7. Delete Task\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Task ID: ";
            cin >> id;
            cout << "Enter Task Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Task Description: ";
            getline(cin, desc);
            manager.addTask(id, name, desc);
            break;

        case 2:
            cout << "Enter Task ID to add dependency: ";
            cin >> id;
            cout << "Enter Dependency Task ID: ";
            cin >> depID;
            manager.addDependency(id, depID);
            break;

        case 3:
            cout << "Enter Task ID to mark as completed: ";
            cin >> id;
            manager.markTaskCompleted(id);
            break;

        case 4:
            manager.undoCompletion();
            break;

        case 5:
            manager.redoCompletion();
            break;

        case 6:
            manager.viewTasks();
            break;

        case 7:
            cout << "Enter Task ID to delete: ";
            cin >> id;
            manager.deleteTask(id);
            break;

        case 8:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 8);

    return 0;
}
