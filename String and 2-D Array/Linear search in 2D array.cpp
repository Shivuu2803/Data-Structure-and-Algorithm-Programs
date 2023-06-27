#include <iostream>
using namespace std;

bool linearSearch2DArray(int** arr, int rows, int cols, int target) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (arr[i][j] == target) 
            {
                return true;
            }
        }
    }
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

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    bool found = linearSearch2DArray(arr, rows, cols, target);

    if (found) 
    {
        cout << "Target value found in the array." << endl;
    } else 
    {
        cout << "Target value not found in the array." << endl;
    }

    // Deallocate the memory
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
