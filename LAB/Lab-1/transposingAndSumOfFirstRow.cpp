/*
Transpose the 2D array and calculate the sum of the first row of the array
*/

#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int A[rows][cols];

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Element at [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    int t_A[cols][rows];

    // Transposing the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            t_A[j][i] = A[i][j];
        }
    }

    // Displaying the original array
    cout << "Original Array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Displaying the transposed array
    cout << "Transposed Array:" << endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << t_A[i][j] << " ";
        }
        cout << endl;
    }

    // Calculating the sum of the first row of the transposed array
    int sum = 0;
    for (int j = 0; j < rows; j++)
    {
        sum += t_A[0][j];
    }

    cout << "Sum of the first row of the transposed array: " << sum << endl;
    return 0;
}
