/*
Call by value through a pointer in c++
*/

#include <iostream>
using namespace std;

// Function to swap two integers using pointers
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After swap in swap function: a = " << a << ", b = " << b << endl;
}

int main()
{
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap in main function: a = " << a << ", b = " << b << endl;
    return 0;
}