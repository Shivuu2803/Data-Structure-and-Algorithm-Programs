#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into a single sorted subarray
void merge(vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;   // Size of the left subarray
    int n2 = right - mid;      // Size of the right subarray

    // Create temporary subarrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to the temporary subarrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary subarrays back into arr[left..right]
    int i = 0;      // Initial index of the first subarray
    int j = 0;      // Initial index of the second subarray
    int k = left;   // Initial index of the merged subarray

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightArr[], if any
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves recursively
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (const auto& element : arr) 
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
