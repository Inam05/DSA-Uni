#include <iostream>
using namespace std;
int main()
{
    const int rows = 5;
    const int cols = 5;
    int array[rows][cols];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = (i + 1) + (j + 1) * 10;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
