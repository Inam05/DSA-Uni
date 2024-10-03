#include <iostream>
using namespace std;

class StackOperations
{
protected:
    int *arr;
    int maxSize;
    int currentSize;

public:
    StackOperations(int size)
    {
        maxSize = size;
        currentSize = 0;
        arr = new int[maxSize];
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == maxSize;
    }

    void push(int value)
    {
        if (!isFull())
        {
            arr[currentSize++] = value;
        }
        else
        {
            cout << "Stack is full. Cannot push " << value << endl;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            cout << "Popped: " << arr[--currentSize] << endl;
        }
        else
        {
            cout << "Stack is empty. Nothing to pop." << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i < currentSize; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~StackOperations()
    {
        delete[] arr;
    }
};

class StackManager : public StackOperations
{
public:
    StackManager(int size) : StackOperations(size) {}

    void manageStack()
    {
        int choice, value;
        do
        {
            cout << "1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
            }
        } while (choice != 4);
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    StackManager stack(size);
    stack.manageStack();
    return 0;
}
