#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) 
{
    // Base case: If the low index becomes greater than the high index, target is not found
    if (low > high)
        return -1;

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // If the middle element is the target, return the index
    if (arr[mid] == target)
        return mid;

    // If the target is less than the middle element, search the left half
    if (target < arr[mid])
        return binarySearch(arr, low, mid - 1, target);

    // Otherwise, search the right half
    return binarySearch(arr, mid + 1, high, target);
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
