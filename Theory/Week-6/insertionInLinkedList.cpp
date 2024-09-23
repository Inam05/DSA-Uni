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

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void addAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtPosition(int value, int pos)
    {
        if (pos == 1)
        {
            addAtBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, value, pos;

    while (true)
    {
        cout << "Where do you want to add the new node?\n1. Beginning\n2. End\n3. Specific position\n0. Quit\n";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        cout << "Enter value: ";
        cin >> value;

        if (choice == 1)
        {
            list.addAtBeginning(value);
        }
        else if (choice == 2)
        {
            list.addAtEnd(value);
        }
        else if (choice == 3)
        {
            cout << "Enter position: ";
            cin >> pos;
            list.addAtPosition(value, pos);
        }
    }

    cout << "Final Linked List: ";
    list.display();

    return 0;
}