/*
Create a 2D array of size[3][2] in c++ . Perform these steps:
1. Search for a specific value within the array
2. Display the value in the array that are greater than 5
3. Calculate and display the sum of all the elements in the array 
*/

#include <iostream>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 2;
    int array[rows][cols];

    cout << "Enter " << rows * cols << " elements for the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> array[i][j];
        }
    }

    // Step 1: Search for a specific value within the array
    int searchValue;
    cout << "Enter a value to search for in the array: ";
    cin >> searchValue;

    bool found = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] == searchValue) {
                cout << "Value " << searchValue << " found at position [" << i << "][" << j << "]" << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Value " << searchValue << " not found in the array." << endl;
    }

    // Step 2: Display the values in the array that are greater than 5
    cout << "Values greater than 5 in the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] > 5) {
                cout << array[i][j] << " ";
            }
        }
    }
    cout << endl;

    // Step 3: Calculate and display the sum of all the elements in the array
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
    }
    cout << "Sum of all elements in the array: " << sum << endl;

    return 0;
}