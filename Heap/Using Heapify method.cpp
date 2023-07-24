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

void buildHeap(vector<int>& heap) 
{
    int size = heap.size();

    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(heap, size, i);
    }
}

void printHeap(const vector<int>& heap) 
{
    for (int i : heap)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> heap = { 10, 20, 15, 30, 5 };

    // Building the heap
    buildHeap(heap);

    // Printing the heap
    cout << "Heap: ";
    printHeap(heap);

    return 0;
}
