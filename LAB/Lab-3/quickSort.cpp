#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 27, 78, 101};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Quick Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
Select the pivot element from the array (typically the last element).
Initialize a pointer (i) to keep track of the partitioning index. Set it to one less than the starting index (low - 1).
Iterate through the array from the starting index (low) to the element before the pivot (high - 1).
For each element, if it is smaller than the pivot, increment the pointer (i) and swap the current element with the element at the pointer position (i).
After the loop, swap the pivot element with the element at the pointer position plus one (i + 1). This positions the pivot in its correct sorted location.
Recursively apply the above steps to the sub-arrays on either side of the pivot.
Continue the recursive partitioning and sorting until the entire array is sorted.
*/