#include <iostream>
using namespace std;

// Node class representing each element of the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node with given data
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// LinkedList class to handle list operations
class LinkedList
{
public:
    Node *head;

    // Constructor to initialize an empty linked list
    LinkedList()
    {
        head = nullptr;
    }

    // Function to append a new node to the list
    void append(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Recursive function to merge two sorted linked lists
    static Node *mergeSortedList(Node *a, Node *b)
    {
        // Base cases
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;

        Node *result;

        // Pick either a or b, and recur
        if (a->data <= b->data)
        {
            result = a;
            result->next = mergeSortedList(a->next, b);
        }
        else
        {
            result = b;
            result->next = mergeSortedList(a, b->next);
        }

        return result;
    }

    // Function to display the linked list
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main()
{
    // Create first linked list: 2 -> 4 -> 8 -> 9
    LinkedList list1;
    list1.append(2);
    list1.append(4);
    list1.append(8);
    list1.append(9);

    // Create second linked list: 1 -> 3 -> 8 -> 10
    LinkedList list2;
    list2.append(1);
    list2.append(3);
    list2.append(8);
    list2.append(10);

    // Merge the two sorted linked lists
    LinkedList resultList;
    resultList.head = LinkedList::mergeSortedList(list1.head, list2.head);

    cout << "Merged Linked List is:" << endl;
    resultList.display();

    return 0;
}
