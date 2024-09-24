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

    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (pos == 1)
        {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Invalid position." << endl;
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

    bool searchValue(int value)
    {
        Node *temp = head;
        int position = 1; 
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "Value " << value << " found at node " << position << "." << endl;
                return true;
            }
            temp = temp->next;
            position++; 
        }

        cout << "Value " << value << " not found in the list." << endl;
        return false;
    }

    int findTotalNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    LinkedList list;
    int choice, value, pos, action;

    while (true)
    {
        cout << "Choose an action:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search for a value\n";
        cout << "4. Find total number of nodes\n";
        cout << "0. Quit\n";
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
            cout << "Where do you want to delete the node from?\n1. Beginning\n2. End\n3. Specific position\n";
            cin >> choice;

            if (choice == 1)
            {
                list.deleteAtBeginning();
            }
            else if (choice == 2)
            {
                list.deleteAtEnd();
            }
            else if (choice == 3)
            {
                cout << "Enter the position to delete: ";
                cin >> pos;
                list.deleteAtPosition(pos);
            }
        }
        else if (action == 3)
        {
            cout << "Enter the value to search: ";
            cin >> value;
            if (list.searchValue(value))
            {
                cout << "Value found in the list." << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }
        }
        else if (action == 4)
        {
            cout << "Total number of nodes: " << list.findTotalNodes() << endl;
        }
    }

    cout << "Final Linked List: ";
    list.display();

    return 0;
}
