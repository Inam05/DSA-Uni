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
            cin >> arr[i][j];
    }

    for (int i = 0; i < rows; i++)
    {
        int maxElement = arr[i][0];
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] > maxElement)
                maxElement = arr[i][j];
        }
        cout << "Maximum element in row " << i + 1 << ": " << maxElement << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
