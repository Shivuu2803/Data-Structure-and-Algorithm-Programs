#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>& heap, int heapSize, int i) 
{
    int largest = i;  // Initialize the largest element as the root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // Compare the left child with the root
    if (left < heapSize && heap[left] > heap[largest])
    {
        largest = left;
    }

    // Compare the right child with the current largest
    if (right < heapSize && heap[right] > heap[largest])
    {
        largest = right;
    }

    // If the largest element is not the root, swap them and heapify the affected subtree
    if (largest != i) 
    {
        swap(heap[i], heap[largest]);
        heapify(heap, heapSize, largest);
    }
}

// Merge two binary max heaps
vector<int> mergeHeaps(const vector<int>& heap1, const vector<int>& heap2) 
{
    vector<int> mergedHeap;
    mergedHeap.reserve(heap1.size() + heap2.size());

    // Copy the elements from the first heap
    for (int num : heap1)
    {
        mergedHeap.push_back(num);
    }

    // Copy the elements from the second heap
    for (int num : heap2)
    {
        mergedHeap.push_back(num);
    }

    int mergedHeapSize = mergedHeap.size();

    // Perform heapify operation on each internal node in reverse order
    for (int i = mergedHeapSize / 2 - 1; i >= 0; --i)
    {
        heapify(mergedHeap, mergedHeapSize, i);

    }
    return mergedHeap;
}

// Print the elements of a heap
void printHeap(const vector<int>& heap) 
{
    for (int num : heap)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> heap1 = {10, 8, 6, 4, 2};
    vector<int> heap2 = {9, 7, 5, 3, 1};

    cout << "Heap 1: ";
    printHeap(heap1);

    cout << "Heap 2: ";
    printHeap(heap2);

    vector<int> mergedHeap = mergeHeaps(heap1, heap2);

    cout << "Merged Heap: ";
    printHeap(mergedHeap);

    return 0;
}
