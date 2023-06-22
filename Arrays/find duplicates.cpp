#include <iostream>
using namespace std;

void findDuplicates(int arr[], int size) 
{
    const int maxElement = 1000;  // Assuming the maximum element in the array

    int frequency[maxElement + 1] = {0};

    for (int i = 0; i < size; i++) 
    {
        frequency[arr[i]]++;
    }

    cout << "Duplicates: ";
    for (int i = 0; i <= maxElement; i++) 
    {
        if (frequency[i] > 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() 
{
    int arr[] = {1, 2, 3, 2, 4, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}
