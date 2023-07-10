#include <iostream>
using namespace std;

class InputRestrictedQueue 
{
public:
    int* arr;           // array to store queue elements
    int capacity;       // maximum capacity of the queue
    int front;          // front points to the front element in the queue
    int rear;           // rear points to the last element in the queue
    int count;          // current size of the queue

public:
    InputRestrictedQueue(int capacity) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~InputRestrictedQueue() 
    {
        delete[] arr;
    }

    void enqueue(int item) 
    {
        if (isFull()) 
        {
            // Queue is full, discard the oldest element (front) and add the new element at the rear
            cout << "Queue is full. Discarding oldest element: " << arr[front] << endl;
            front = (front + 1) % capacity;
            count--;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isEmpty() 
    {
        return count == 0;
    }

    bool isFull() 
    {
        return count == capacity;
    }
};

int main() 
{
    InputRestrictedQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);  // This will discard the oldest element (10) to make space

    while (!queue.isEmpty()) {
        int item = queue.dequeue();
        cout << "Dequeued: " << item << endl;
    }

    return 0;
}
