#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ArrayElement 
{
    int value;     // Value of the element
    int arrayIndex; // Index of the array the element belongs to
    int elementIndex; // Index of the element in its array

    ArrayElement(int val, int arrIdx, int elemIdx)
    {
        this->value = val;
        this->arrayIndex = arrIdx;
        this->elementIndex = elemIdx;
    }
        
};

struct CompareArrayElement 
{
    bool operator()(const ArrayElement& a, const ArrayElement& b) 
    {
        return a.value > b.value; // Min heap based on value
    }
};

// Function to merge K sorted arrays into a single sorted array
vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) 
{
    vector<int> mergedArray;
    int k = arrays.size();

    // Create a priority queue (min heap) of size K
    priority_queue<ArrayElement, vector<ArrayElement>, CompareArrayElement> minHeap;

    // Insert the first element from each array into the min heap
    for (int i = 0; i < k; i++)
    {
        if (!arrays[i].empty()) 
        {
            minHeap.push(ArrayElement(arrays[i][0], i, 0));
        }
    }

    // Merge the arrays until the min heap becomes empty
    while (!minHeap.empty()) 
    {
        // Get the smallest element from the min heap
        ArrayElement minElement = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the merged array
        mergedArray.push_back(minElement.value);

        int arrIndex = minElement.arrayIndex;
        int elemIndex = minElement.elementIndex + 1;

        // Check if there are more elements in the current array
        if (elemIndex < arrays[arrIndex].size()) 
        {
            // Insert the next element from the current array into the min heap
            minHeap.push(ArrayElement(arrays[arrIndex][elemIndex], arrIndex, elemIndex));
        }
    }

    return mergedArray;
}

// Function to print an array
void printArray(const vector<int>& arr) 
{
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{
    vector<vector<int>> arrays = 
    {
        {1, 3, 5, 7},
        {2, 4, 6},
        {0, 8, 9}
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged Array: ";
    printArray(mergedArray);

    return 0;
}
