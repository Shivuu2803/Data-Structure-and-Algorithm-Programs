#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) 
{
    stack<int> s;

    // Push all elements of the queue onto a stack
    while (!q.empty()) 
    {
        s.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (!s.empty()) 
    {
        q.push(s.top());
        s.pop();
    }
}

int main() 
{
    queue<int> q;

    // Enqueue elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original queue: ";
    queue<int> originalQ = q; // Create a copy for displaying the original queue

    while (!originalQ.empty()) 
    {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }
    cout << endl;

    // Reverse the queue
    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) 
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
