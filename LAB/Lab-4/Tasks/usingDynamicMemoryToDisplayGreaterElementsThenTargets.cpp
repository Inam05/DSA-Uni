#include <iostream>
using namespace std;

int main()
{
    int size, target;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter " << size << " values for the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
    cout << "Enter the target value: ";
    cin >> target;
    cout << "Numbers larger than the target value:" << endl;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > target)
        {
            cout << array[i] << " ";
        }
    }
    cout << endl;

    delete[] array;

    return 0;
}
