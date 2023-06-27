#include <iostream>
using namespace std;

void wavePrint(int** arr, int rows, int cols) 
{
    for (int j = 0; j < cols; ++j) 
    {
        // For even columns, print elements from top to bottom
        if (j % 2 == 0) 
        {
            for (int i = 0; i < rows; ++i) 
            {
                cout << arr[i][j] << " ";
            }
        }
        // For odd columns, print elements from bottom to top
        else 
        {
            for (int i = rows - 1; i >= 0; --i) 
            {
                cout << arr[i][j] << " ";
            }
        }
    }
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

    cout << "Wave print of the array:" << endl;
    wavePrint(arr, rows, cols);

    // Deallocate the memory
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
