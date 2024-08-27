#include <iostream>
using namespace std;
int main()
{
    // Linear Searching
    int x;
    cout << "Enter the size and elements of an Array : ";
    cin >> x;
    cout << "_________________________________________" << endl;
    int A[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter Number : ";
        cin >> A[i];
    }
    int n;
    cout << "Enter your Number to find : ";
    cin >> n;
    for (int i = 0; i <= x; i++)
    {
        if (n == A[i])
        {
            cout << "Your Number is at the index : " << i;
            return 0;
        }
    }
    cout << "Your number is not found";
    return 0;
}