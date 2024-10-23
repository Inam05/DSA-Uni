#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;     // Array to hold stack elements
    int top;      // Index of the top element in the stack
    int capacity; // Maximum number of elements the stack can hold

public:
    // Constructor to initialize the stack
    Stack(int size)
    {
        arr = new int[size]; // Allocate memory for the stack
        capacity = size;     // Set the capacity
        top = -1;            // Initialize top index
    }

    // Push a value onto the stack
    void push(int value)
    {
        if (top == capacity - 1)
        { // Check if the stack is full
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value; // Increment top and insert the value
    }

    // Pop a value from the stack
    int pop()
    {
        if (isEmpty())
        { // Check if the stack is empty
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return -1 to indicate an error
        }
        return arr[top--]; // Return the top value and decrement top
    }

    // Peek at the top value of the stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1; // Return -1 to indicate an error
        }
        return arr[top]; // Return the top value
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == -1; // Return true if top is -1
    }

    // Display the stack contents
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = top; i >= 0; --i)
        { // Print from top to bottom
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Stack()
    {
        delete[] arr; // Deallocate memory for the stack
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);
    int choice, value;

    while (true)
    {
        cout << "Choose an action:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if empty\n";
        cout << "5. Display stack\n";
        cout << "0. Quit\n";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            value = stack.pop();
            if (value != -1)
            {
                cout << "Popped value: " << value << endl;
            }
            break;
        case 3:
            value = stack.peek();
            if (value != -1)
            {
                cout << "Top value: " << value << endl;
            }
            break;
        case 4:
            cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            stack.display();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
