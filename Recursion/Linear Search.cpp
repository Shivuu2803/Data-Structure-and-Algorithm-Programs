#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target, int index = 0) 
{
    // Base case: If the index reaches the end of the array, target is not found
    if (index >= size)
        return -1;

    // If the target is found at the current index, return the index
    if (arr[index] == target)
        return index;

    // Recursively search for the target in the remaining elements
    return linearSearch(arr, size, target, index + 1);
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}
