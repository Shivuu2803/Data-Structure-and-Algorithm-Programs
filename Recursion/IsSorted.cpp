#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) 
{

    // Base case: if the array has zero or one element, it is considered sorted
    if (size <= 1)
        return true;

    // Check if the last two elements are in non-decreasing order
    if (arr[size - 2] > arr[size - 1])
        return false;

    // Recursively check if the array excluding the last element is sorted
    return isSorted(arr, size - 1);
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    bool sorted = isSorted(arr, size);
    if (sorted)
    {
        cout << "The array is sorted in non-decreasing order." << endl;
    }
    else
    {
        cout << "The array is not sorted in non-decreasing order." << endl;
    }

    return 0;
}
