#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedListStack
{
    Node *top;

public:
    LinkedListStack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int element)
    {
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        else
        {
            int poppedValue = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return poppedValue;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack after pushes: ";
    stack.display();
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack after pop: ";
    stack.display();
    return 0;
}
