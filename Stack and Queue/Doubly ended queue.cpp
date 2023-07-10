#include <iostream>
#include <deque>
using namespace std;

int main() 
{
    deque<int> dq;

    // Adding elements at the back of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Adding elements at the front of the deque
    dq.push_front(5);
    dq.push_front(2);
    dq.push_front(1);

    // Displaying the elements of the deque
    cout << "Deque elements: ";
    for (int x : dq) 
    {
        cout << x << " ";
    }
    cout << endl;

    // Accessing the front and back elements of the deque
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Removing elements from the front and back of the deque
    dq.pop_front();
    dq.pop_back();

    // Displaying the updated elements of the deque
    cout << "Updated deque elements: ";
    for (int x : dq) 
    {
        cout << x << " ";
    }
    cout << endl;

    // Checking if the deque is empty
    if (dq.empty()) 
    {
        cout << "Deque is empty." << endl;
    } 
    else 
    {
        cout << "Deque is not empty." << endl;
        cout << "Size of the deque: " << dq.size() << endl;
    }

    return 0;
}
