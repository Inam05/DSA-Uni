#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool isSwapped;
    for (int i = n; i > 0; --i)
    {
        isSwapped = false;

        for (int j = 0; j < i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)
            break;
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
