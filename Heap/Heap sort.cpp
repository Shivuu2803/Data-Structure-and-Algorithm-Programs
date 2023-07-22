#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int size, int index) 
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;

    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index) 
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(vector<int>& arr) 
{
    int size = arr.size();

    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, size, i);
    }

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) 
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
