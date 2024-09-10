#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter " << size << " values for the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }

    sort(array, array + size);

    int maxCount = 0;
    int currentCount = 1;

    for (int i = 1; i < size; ++i)
    {
        if (array[i] == array[i - 1])
        {
            currentCount++;
        }
        else
        {
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
            }
            currentCount = 1;
        }
    }
    if (currentCount > maxCount)
    {
        maxCount = currentCount;
    }
    cout << "Most repeated values:" << endl;
    currentCount = 1;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] == array[i - 1])
        {
            currentCount++;
        }
        else
        {
            if (currentCount == maxCount)
            {
                cout << array[i - 1] << " ";
            }
            currentCount = 1;
        }
    }

    if (currentCount == maxCount)
    {
        cout << array[size - 1];
    }
    cout << endl;

    delete[] array;

    return 0;
}
