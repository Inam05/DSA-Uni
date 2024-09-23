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
        {
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int pos)
    {
        if (head == nullptr)
        {
            return;
        }
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
        {
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
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
    int choice, value, pos, action;

    while (true)
    {
        cout << "Choose an action:\n1. Insert\n2. Delete\n0. Quit\n";
        cin >> action;

        if (action == 0)
        {
            break;
        }

        if (action == 1)
        {
            cout << "Where do you want to add the new node?\n1. Beginning\n2. End\n3. Specific position\n";
            cin >> choice;

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
        else if (action == 2)
        {
            cout << "Enter the position to delete: ";
            cin >> pos;
            list.deleteAtPosition(pos);
        }
    }

    cout << "Final Linked List: ";
    list.display();

    return 0;
}
