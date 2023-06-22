#include <iostream>
#include <vector>
using namespace std;

bool isSortedAndRotated(const vector<int>& arr) 
{
    int n = arr.size();
    int minIndex = 0;

    // Find the index of the minimum element
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] < arr[minIndex]) 
        {
            minIndex = i;
        }
    }

    // If the minimum index is at the last position, the array is not sorted and rotated
    // Otherwise, check if the array is sorted in ascending order after the minimum index
    if (minIndex == n - 1) 
    {
        return false;
    } else 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            int curr = (minIndex + i) % n;
            int next = (minIndex + i + 1) % n;

            if (arr[curr] > arr[next]) 
            {
                return false;
            }
        }
        return true;
    }
}

int main() 
{
    vector<int> arr1 = {4, 5, 6, 7, 1, 2, 3};
    vector<int> arr2 = {1, 2, 3, 9, 5, 6, 7};
    vector<int> arr3 = {7, 1, 2, 3, 4, 5, 6};

    if (isSortedAndRotated(arr1)) 
    {
        cout << "arr1 is a sorted and rotated array.\n";
    } else 
    {
        cout << "arr1 is not a sorted and rotated array.\n";
    }

    if (isSortedAndRotated(arr2)) 
    {
        cout << "arr2 is a sorted and rotated array.\n";
    } else 
    {
        cout << "arr2 is not a sorted and rotated array.\n";
    }

    if (isSortedAndRotated(arr3)) 
    {
        cout << "arr3 is a sorted and rotated array.\n";
    } else 
    {
        cout << "arr3 is not a sorted and rotated array.\n";
    }

    return 0;
}
