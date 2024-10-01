#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail; // New tail pointer

    LinkedList()
    {
        head = nullptr;
        tail = nullptr; // Initialize tail
    }

    void addAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head != nullptr)
        {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void addAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode; // Both head and tail point to the new node
        }
        else
        {
            tail->next = newNode; // Link the current tail to the new node
            newNode->prev = tail; // Link new node's previous to the current tail
            tail = newNode;       // Update the tail to the new node
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
        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head == tail) // Only one node in the list
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *temp = tail;    // Start from the tail
        tail = tail->prev;    // Move the tail pointer back
        tail->next = nullptr; // Set the new tail's next to null
        delete temp;          // Delete the old tail node
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
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = temp;
        }
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

    void displayReverse()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
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

    int findMiddleNode()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return -1;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
        cout << "5. Find the middle node\n";
        cout << "6. Display list in reverse\n";
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
            list.searchValue(value);
        }
        else if (action == 4)
        {
            cout << "Total number of nodes: " << list.findTotalNodes() << endl;
        }
        else if (action == 5)
        {
            cout << "Middle node value: " << list.findMiddleNode() << endl;
        }
        else if (action == 6)
        {
            cout << "Reversed List: ";
            list.displayReverse();
        }
    }

    cout << "Final Linked List: ";
    list.display();

    return 0;
}
