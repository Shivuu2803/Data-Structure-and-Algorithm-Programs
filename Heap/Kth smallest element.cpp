#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int size, int index) 
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
    {
        largest = left;

    }
    if (right < size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != index) 
    {
        swap(heap[index], heap[largest]);
        heapify(heap, size, largest);
    }
}

int findKthSmallest(vector<int>& heap, int k) 
{
    int size = heap.size();

    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(heap, size, i);
    }

    // Extract k elements from the heap
    for (int i = 0; i < k; i++) 
    {
        swap(heap[0], heap[size - 1]);
        size--;
        heapify(heap, size, 0);
    }

    // Return the kth smallest element
    return heap[size];
}

int main() 
{
    vector<int> heap = { 12, 11, 13, 5, 6, 7 };
    int k = 3;

    cout << "Heap: ";
    for (int i : heap)
    {
        cout << i << " ";
    }
    cout << endl;

    int kthSmallest = findKthSmallest(heap, k);
    cout << "The " << k << "th smallest element: " << kthSmallest << endl;

    return 0;
}
