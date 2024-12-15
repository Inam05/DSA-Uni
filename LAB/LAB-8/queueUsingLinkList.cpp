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

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue function to add an element to the queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue function to remove an element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return -1;
        }
        Node *temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr; // If the queue becomes empty
        }
        delete temp;
        return value;
    }

    // Peek function to see the front element of the queue
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to display the contents of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        cout << "Queue contents: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue(); // Dequeue all nodes
        }
    }
};

int main()
{
    Queue queue;
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
