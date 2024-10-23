#include <iostream>
using namespace std;

class ArrayStack
{
    int max_size;
    int *stack;
    int top;

public:
    ArrayStack(int size)
    {
        max_size = size;
        stack = new int[max_size];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == max_size - 1;
    }

    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack overflow\n";
        }
        else
        {
            stack[++top] = element;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        else
        {
            return stack[top--];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    ArrayStack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack after pushes: ";
    stack.display();
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack after pop: ";
    stack.display();
    return 0;
}
