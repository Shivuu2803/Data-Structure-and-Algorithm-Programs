#include <iostream>
#include <vector>
using namespace std;

vector<int> addArrays(vector<int>& arr1, vector<int>& arr2) 
{
    int n = arr1.size();
    std::vector<int> result(n);

    for (int i = 0; i < n; i++) 
    {
        result[i] = arr1[i] + arr2[i];
    }

    return result;
}

int main() 
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4, 5, 6};

    cout << "Array 1: ";
    for (int num : arr1) 
    {
        std::cout << num << " ";
    }

    cout << "\nArray 2: ";
    for (int num : arr2) 
    {
        std::cout << num << " ";
    }

    vector<int> result = addArrays(arr1, arr2);

    cout << "\nResult Array: ";
    for (int num : result) 
    {
        std::cout << num << " ";
    }

    return 0;
}
