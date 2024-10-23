#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        if (front == -1)
        {
            front = rear; 
        }
        cout << "Inserted " << value << "\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Removed " << arr[front] << "\n";
        front = (front + 1) % capacity;
        size--;
        if (isEmpty())
        {
            front = rear = -1; 
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    CircularQueue q(9); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    cout << "Front element: " << q.getFront() << "\n";
    cout << "Rear element: " << q.getRear() << "\n";

    q.dequeue();
    q.enqueue(110); // Demonstrating circular behavior

    cout << "Front element: " << q.getFront() << "\n";
    cout << "Rear element: " << q.getRear() << "\n";

    return 0;
}
