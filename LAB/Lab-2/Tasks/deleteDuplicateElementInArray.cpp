#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int size)
{
    int newSize = size;

    for (int i = 0; i < newSize; i++)
    {
        for (int j = i + 1; j < newSize; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < newSize - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                newSize--;
                j--;
            }
        }
    }

    return newSize;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, size);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
