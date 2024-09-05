#include <iostream>
using namespace std;

void countOccurrences(const int arr[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty." << endl;
        return;
    }

    int currentElement = arr[0];
    int count = 1;

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] == currentElement)
        {
            count++;
        }
        else
        {
            cout << "Element " << currentElement << " occurs " << count << " times." << endl;
            currentElement = arr[i];
            count = 1;
        }
    }

    cout << "Element " << currentElement << " occurs " << count << " times." << endl;
}

int main()
{
    int sortedArray[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5};
    int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    countOccurrences(sortedArray, arraySize);

    return 0;
}
