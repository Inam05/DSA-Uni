#include <iostream>
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

    cout << "Even values in the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << " ";
        }
    }
    cout << endl;

    delete[] array;

    return 0;
}
