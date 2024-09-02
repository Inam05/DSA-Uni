#include <iostream>
using namespace std;
int main()
{
    int *ptr;
    int x;
    ptr = &x;
    cout << "x=" << x << endl;
    cout << "*ptr=" << *ptr << endl;
    *ptr += 5;
    cout << "x=" << x << endl;
    cout << "*ptr=" << *ptr << endl;
    (*ptr)++;
    cout << "x=" << x << endl;
    cout << "*ptr=" << *ptr << endl;
    return 0;
}