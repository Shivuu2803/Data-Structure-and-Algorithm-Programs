#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) 
{
    if (k < 0 || k > q.size()) 
    {
        cout << "Invalid value of k." << endl;
        return;
    }

    stack<int> s;
    
    // Push the first k elements of the queue onto the stack
    for (int i = 0; i < k; i++) 
    {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the elements back into the queue
    while (!s.empty()) 
    {
        q.push(s.top());
        s.pop();
    }

    // Move the remaining (n - k) elements to the back of the queue
    for (int i = 0; i < q.size() - k; i++) 
    {
        q.push(q.front());
        q.pop();
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
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    int k = 5; // Number of elements to reverse

    cout << "Original queue: ";
    queue<int> originalQ = q; // Create a copy for displaying the original queue

    while (!originalQ.empty()) 
    {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }
    cout << endl;

    // Reverse the first k elements
    reverseFirstK(q, k);

    cout << "Reversed first " << k << " elements: ";
    while (!q.empty()) 
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
