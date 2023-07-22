#include <iostream>
#include <vector>
using namespace std;

void insertIntoHeap(vector<int>& heap, int value) 
{
    heap.push_back(value);

    int index = heap.size() - 1;

    while (index > 0) 
    {
        int parent = (index - 1) / 2;

        if (heap[index] > heap[parent]) 
        {
            swap(heap[index], heap[parent]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}

void deleteFromHeap(vector<int>& heap) 
{
    if (heap.empty()) 
    {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();

    int index = 0;
    int size = heap.size();

    while (true) 
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index) 
        {
            swap(heap[index], heap[largest]);
            index = largest;
        } 
        else 
        {
            break;
        }
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
    vector<int> heap;

    insertIntoHeap(heap, 10);
    insertIntoHeap(heap, 20);
    insertIntoHeap(heap, 15);
    insertIntoHeap(heap, 30);
    insertIntoHeap(heap, 5);

    cout << "Heap: ";
    printHeap(heap);

    deleteFromHeap(heap);

    cout << "Updated Heap: ";
    printHeap(heap);

    return 0;
}
