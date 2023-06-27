#include <iostream>
using namespace std;

bool binarySearch2D(int** arr, int rows, int cols, int target) 
{
    int left = 0;           // Leftmost column index
    int right = cols - 1;   // Rightmost column index
    int top = 0;            // Top row index
    int bottom = rows - 1;  // Bottom row index

    while (left <= right && top <= bottom) 
    {
        int midRow = top + (bottom - top) / 2;     // Mid row index
        int midCol = left + (right - left) / 2;    // Mid column index
        int midElement = arr[midRow][midCol];      // Element at the middle

        // Check if the middle element is equal to the target
        if (midElement == target) 
        {
            return true;
        }
        // If the target is less than the middle element,
        // eliminate the right half of the current row and current column
        else if (midElement > target) 
        {
            if (midCol > left) 
            {
                right = midCol - 1;  // Exclude the right half of the current column
            }
            else 
            {
                bottom = midRow - 1; // Exclude the bottom half of the current row
            }
        }
        // If the target is greater than the middle element,
        // eliminate the left half of the current row and current column
        else 
        {
            if (midCol < right) 
            {
                left = midCol + 1;   // Exclude the left half of the current column
            }
            else 
            {
                top = midRow + 1;    // Exclude the top half of the current row
            }
        }
    }

    // If the target is not found
    return false;
}

int main() 
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
    }

    cout << "Enter the elements of the array in sorted order:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    bool found = binarySearch2D(arr, rows, cols, target);

    if (found) 
    {
        cout << "Element " << target << " found in the array." << endl;
    } else 
    {
        cout << "Element " << target << " not found in the array." << endl;
    }

    // Deallocate the memory
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
