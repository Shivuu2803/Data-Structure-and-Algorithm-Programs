#include <iostream>
#include <queue>
using namespace std;

class OutputRestrictedQueue 
{
private:
    queue<int> q;
    int maxSize;

public:
    OutputRestrictedQueue(int size) 
    {
        maxSize = size;
    }

    void enqueue(int value) 
    {
        if (q.size() == maxSize) 
        {
            cout << "Queue is full. Dequeue an element before enqueueing." << endl;
        } else 
        {
            q.push(value);
        }
    }

    void dequeue() 
    {
        if (q.empty()) 
        {
            cout << "Queue is empty. No elements to dequeue." << endl;
        } 
        else 
        {
            q.pop();
        }
    }

    void displayQueue() 
    {
        if (q.empty()) 
        {
            cout << "Queue is empty." << endl;
        }
        else 
        {
            queue<int> temp = q;
            while (!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() 
{
    OutputRestrictedQueue queue(5);

    queue.displayQueue();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    queue.displayQueue();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.displayQueue();

    return 0;
}
