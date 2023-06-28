#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n) 
{
    // Base case: If only one element is remaining, the array is already sorted
    if (n == 1)
        return;

    // Perform one pass of bubble sort
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] > arr[i + 1]) 
        {
            // Swap adjacent elements if they are in the wrong order
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursively sort the remaining (n - 1) elements
    bubbleSort(arr, n - 1);
}

int main() 
{
    vector<int> arr;
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) 
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    for (const auto& element : arr) 
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
