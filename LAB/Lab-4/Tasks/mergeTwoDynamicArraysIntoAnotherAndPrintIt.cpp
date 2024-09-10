#include <iostream>
using namespace std;

int main()
{
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    int *array1 = new int[size1];
    cout << "Enter " << size1 << " values for the first array:" << endl;
    for (int i = 0; i < size1; ++i)
    {
        cin >> array1[i];
    }
    cout << "Enter the size of the second array: ";
    cin >> size2;
    int *array2 = new int[size2];
    cout << "Enter " << size2 << " values for the second array:" << endl;
    for (int i = 0; i < size2; ++i)
    {
        cin >> array2[i];
    }
    int *mergedArray = new int[size1 + size2];
    for (int i = 0; i < size1; ++i)
    {
        mergedArray[i] = array1[i];
    }
    for (int i = 0; i < size2; ++i)
    {
        mergedArray[size1 + i] = array2[i];
    }
    cout << "Merged array:" << endl;
    for (int i = 0; i < size1 + size2; ++i)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    delete[] array1;
    delete[] array2;
    delete[] mergedArray;

    return 0;
}
