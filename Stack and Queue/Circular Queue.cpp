#include <iostream>
using namespace std;

class CircularQueue 
{
public:
    int *arr;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int capacity) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue() 
    {
        delete[] arr;
    }

    bool isEmpty() 
    {
        return (size == 0);
    }

    bool isFull() 
    {
        return (size == capacity);
    }

    void enqueue(int data) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow. Cannot enqueue " << data << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;

        if (front == -1) 
        {
            front = rear;
        }

        cout << data << " enqueued successfully." << endl;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow. Cannot dequeue." << endl;
            return;
        }

        int data = arr[front];
        arr[front] = 0;
        size--;

        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % capacity;
        }

        cout << data << " dequeued successfully." << endl;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";

        int count = 0;
        int i = front;

        while (count < size) 
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main() 
{
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.display();

    queue.enqueue(6);
    queue.enqueue(7);

    queue.display();

    return 0;
}
