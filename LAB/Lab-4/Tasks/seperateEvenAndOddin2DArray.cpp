#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int *[rows];
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Even numbers:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] % 2 == 0)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    cout << "Odd numbers:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] % 2 != 0)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
