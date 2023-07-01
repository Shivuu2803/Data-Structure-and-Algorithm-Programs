#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
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

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (const auto& element : arr) 
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
