#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue 
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    {
        return (front == -1 && rear == -1);
    }

    bool isFull() 
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Error: Queue is full." << endl;
            return;
        } 
        else if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Error: Queue is empty." << endl;
            return;
        } 
        else if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getFront() 
    {
        if (isEmpty()) 
        {
            cout << "Error: Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() 
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (i != rear) 
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() 
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();
    queue.display();

    return 0;
}
