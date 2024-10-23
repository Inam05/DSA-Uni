#include <iostream>
using namespace std;

// Node structure for the singly linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Stack class using a singly linked list
class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    Stack()
    {
        top = nullptr; // Initialize the top pointer
    }

    // Push a value onto the stack
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top; // New node points to the current top
        top = newNode;       // Update the top pointer
    }

    // Pop a value from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return -1 to indicate an error
        }
        Node *temp = top;            // Temporary pointer to the top node
        int poppedValue = top->data; // Store the value to return
        top = top->next;             // Update the top pointer
        delete temp;                 // Delete the old top node
        return poppedValue;          // Return the popped value
    }

    // Peek at the top value of the stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1; // Return -1 to indicate an error
        }
        return top->data; // Return the top value
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr; // Return true if top is null
    }

    // Display the stack contents
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *temp = top;
        cout << "Stack contents: ";
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Pop all nodes
        }
    }
};

int main()
{
    Stack stack;
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
