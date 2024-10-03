#include <iostream>
using namespace std;

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

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack()
    {
        top = nullptr;
        count = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int getCount()
    {
        return count;
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Count Elements\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.display();
            break;

        case 4:
            cout << "Number of elements in stack: " << stack.getCount() << "\n";
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
