#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        data = data;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void display()
    {
        Node *tail = head;
        while (tail != nullptr)
        {
            cout << tail->data << " ";
            tail = tail->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    return 0;
}
