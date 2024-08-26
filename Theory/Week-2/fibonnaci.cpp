#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int num;

    cout << "Enter a non-negative integer for Fibonacci: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    }
    else
    {
        int result = fibonacci(num);
        cout << "Fibonacci number at position " << num << " is: " << result << endl;
    }
    
    return 0;
}