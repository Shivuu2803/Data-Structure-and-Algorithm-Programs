#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(int arr1[], int size1, int arr2[], int size2) 
{
    vector<int> intersection;
    int i = 0, j = 0;

    while (i < size1 && j < size2) 
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        } else if (arr1[i] > arr2[j]) 
        {
            j++;
        } else 
        {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersection;
}

int main() 
{
    int arr1[] = {1, 2, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 2, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> intersection = findIntersection(arr1, size1, arr2, size2);

    cout << "Intersection: ";
    for (int num : intersection) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
