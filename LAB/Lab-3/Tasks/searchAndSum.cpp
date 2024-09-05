#include <iostream>
using namespace std;
int searchAndSum(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            int sum = 0;
            for (int i = 0; i <= mid; ++i)
            {
                sum += arr[i];
            }
            return sum;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int sortedArray[] = {1, 3, 5, 7, 9, 11, 13};
    int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);

    int targetValue = 7;
    int result = searchAndSum(sortedArray, arraySize, targetValue);

    if (result != -1)
    {
        cout << "Value " << targetValue << " found at index. Sum up to this value: " << result << endl;
    }
    else
    {
        cout << "Value " << targetValue << " not found in the array." << endl;
    }

    return 0;
}
