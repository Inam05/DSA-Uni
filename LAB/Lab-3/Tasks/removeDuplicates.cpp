#include <iostream>
using namespace std;
void removeDuplicates(int arr[], int &size)
{
    if (size <= 1)
    {
        return;
    }

    int newSize = 1;

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] != arr[newSize - 1])
        {
            arr[newSize] = arr[i];
            ++newSize;
        }
    }

    size = newSize;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
