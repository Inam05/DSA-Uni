#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int arr[] = {23, 34, 56, 67, 12, 54, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Start a loop from the first index i = 0 to the second-last element i < n-1.
Assume the current index i is the index of the minimum element (min_idx = i).
Start a nested loop from the next element (j = i+1) to the end of the array.
If an element arr[j] is smaller than arr[min_idx], update min_idx to j.
Swap the element at min_idx with the element at i.
Repeat steps 2-5 until the array is sorted.
Print the sorted array.
*/