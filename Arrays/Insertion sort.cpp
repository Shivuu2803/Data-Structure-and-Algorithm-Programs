#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() 
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original Array: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    
    insertionSort(arr);
    
    cout << "\nSorted Array: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    
    return 0;
}
