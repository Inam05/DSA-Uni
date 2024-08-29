#include <iostream>
using namespace std;

int main()
{
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }

    int *ptr = A;
    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }
    return 0;
}