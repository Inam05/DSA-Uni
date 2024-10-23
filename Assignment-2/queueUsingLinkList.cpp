#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
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

// Queue class
class Queue
{
private:
    Node *front; // Pointer to the front node of the queue
    Node *rear;  // Pointer to the rear node of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation to add an element to the queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value); // Create a new node

        if (rear)
        {
            rear->next = newNode; // Link new node at the end
        }
        else
        {
            front = newNode; // If the queue is empty, set front to the new node
        }
        rear = newNode; // Update rear to the new node
    }

    // Dequeue operation to remove an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return -1; // Return -1 to indicate an error
        }

        int value = front->data; // Get the value to be dequeued
        Node *temp = front;      // Temporary pointer to hold the front node
        front = front->next;     // Move front to the next node

        if (!front)
        {
            rear = nullptr; // If the queue is now empty, reset rear
        }

        delete temp;  // Delete the old front node
        return value; // Return the dequeued value
    }

    // Peek operation to view the front element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1; // Return -1 to indicate an error
        }
        return front->data; // Return the front value
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr; // Return true if front is null
    }

    // Display the queue contents
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: ";
        Node *current = front;
        while (current)
        { // Traverse the queue
            cout << current->data << " ";
            current = current->next; // Move to the next node
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue()
    {
        while (!isEmpty())
        { // Dequeue all elements
            dequeue();
        }
    }
};

int main()
{
    Queue queue; // Create a Queue object
    int choice, value;

    while (true)
    {
        cout << "Choose an action:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "0. Quit\n";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            value = queue.dequeue();
            if (value != -1)
            {
                cout << "Dequeued value: " << value << endl;
            }
            break;
        case 3:
            value = queue.peek();
            if (value != -1)
            {
                cout << "Front value: " << value << endl;
            }
            break;
        case 4:
            queue.display();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
