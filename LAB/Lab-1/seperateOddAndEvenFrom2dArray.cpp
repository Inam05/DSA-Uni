/*
seperate the odd and even numbers in a 2D array of [3][3]
the code must be memory efficient that declare the counter variable of odd and even
so loop and size should be declare by it
*/

#include <iostream>
using namespace std;

int main()
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols];
    int evenCount = 0, oddCount = 0;

    // Input the elements of the array
    cout << "Enter the elements of the 3x3 array:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr[i][j];
            // Check if the number is odd or even
            if (arr[i][j] % 2 == 0)
            {
                ++evenCount;
            }
            else
            {
                ++oddCount;
            }
        }
    }

    // Separate arrays for odd and even numbers
    int evenArr[evenCount];
    int oddArr[oddCount];
    int evenIndex = 0, oddIndex = 0;

    // Populate the even and odd arrays
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (arr[i][j] % 2 == 0)
            {
                evenArr[evenIndex++] = arr[i][j];
            }
            else
            {
                oddArr[oddIndex++] = arr[i][j];
            }
        }
    }

    // Output the even and odd numbers
    cout << "Even numbers: ";
    for (int i = 0; i < evenCount; ++i)
    {
        cout << evenArr[i] << " ";
    }
    cout << "\nOdd numbers: ";
    for (int i = 0; i < oddCount; ++i)
    {
        cout << oddArr[i] << " ";
    }

    return 0;
}
