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

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = nullptr;
    }

    void addAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head; // Circular link
        }
        else
        {
            Node *temp = head;
            while (temp->next != head) // Traverse to the last node
            {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head; // Update the last node's next pointer to new head
        }
    }

    void addAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head; // Circular link
        }
        else
        {
            Node *temp = head;
            while (temp->next != head) // Traverse to the last node
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Circular link back to head
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
        for (int i = 1; i < pos - 1 && temp->next != head; i++) // Traverse to the position
        {
            temp = temp->next;
        }
        if (temp->next == head && pos != 2) // Invalid position, early exit
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
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head) // Traverse to the last node
            {
                temp = temp->next;
            }
            Node *toDelete = head;
            head = head->next;
            temp->next = head; // Update the last node's next pointer
            delete toDelete;
        }
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != head) // Traverse to the second last node
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = head; // Circular link back to head
        }
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
        for (int i = 1; i < pos - 1 && temp->next != head; i++) // Traverse to the position
        {
            temp = temp->next;
        }
        if (temp->next == head) // Invalid position
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head); // Loop until we reach back to the head
        cout << endl;
    }

    bool searchValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Value " << value << " not found in the list." << endl;
            return false;
        }
        Node *temp = head;
        int position = 1;
        do
        {
            if (temp->data == value)
            {
                cout << "Value " << value << " found at node " << position << "." << endl;
                return true;
            }
            temp = temp->next;
            position++;
        } while (temp != head);

        cout << "Value " << value << " not found in the list." << endl;
        return false;
    }

    int findTotalNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    int FindMiddleNode()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return -1;
        }

        Node *slow = head;
        Node *fast = head;

        do
        {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != head && fast->next != head);

        return slow->data;
    }
};

int main()
{
    CircularLinkedList list;
    int choice, value, pos, action;

    while (true)
    {
        cout << "Choose an action:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search for a value\n";
        cout << "4. Find total number of nodes\n";
        cout << "5. Find the middle node\n";
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
        else if (action == 5)
        {
            cout << "Middle node value: " << list.FindMiddleNode() << endl;
        }
    }

    cout << "Final Linked List: ";
    list.display();

    return 0;
}
