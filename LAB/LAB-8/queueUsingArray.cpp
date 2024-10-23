#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, capacity;
    int *arr;

public:
    Queue(int size)
    {
        front = 0;
        rear = 0;
        capacity = size;
        arr = new int[capacity];
    }

    void enqueue(int value)
    {
        if (rear == capacity)
        {
            cout << "Queue overflow! Cannot enqueue more elements." << endl;
            return;
        }
        arr[rear++] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return -1;
        }
        int value = arr[front++];
        if (front == rear)
        {
            front = rear = 0;
        }
        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i < rear; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue queue(size);
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
