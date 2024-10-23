#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Add (Push) an element to the stack
    void add(int value)
    {
        if (top >= 99)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " added to the stack." << endl;
    }

    // Remove (Pop) an element from the stack
    void remove()
    {
        if (top < 0)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        cout << arr[top--] << " removed from the stack." << endl;
    }

    // Peek (View) the top element of the stack
    int peak()
    {
        if (top < 0)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\nStack Menu\n";
        cout << "1. Add (Push)\n";
        cout << "2. Remove (Pop)\n";
        cout << "3. Peek (Top element)\n";
        cout << "4. Check if empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            s.add(value);
            break;
        case 2:
            s.remove();
            break;
        case 3:
            value = s.peak();
            if (value != -1)
                cout << "Top element is: " << value << endl;
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
