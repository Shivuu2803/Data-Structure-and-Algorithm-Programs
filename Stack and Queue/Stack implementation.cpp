#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Checking if the stack is empty
    if (myStack.empty()) 
    {
        cout << "Stack is empty" << endl;
    }
    else 
    {
        cout << "Stack is not empty" << endl;
    }

    // Accessing the top element of the stack
    cout << "Top element: " << myStack.top() << endl;

    // Popping elements from the stack
    myStack.pop();
    myStack.pop();

    // Checking the size of the stack
    cout << "Stack size: " << myStack.size() << endl;

    // Accessing the top element after popping
    if (!myStack.empty()) 
    {
        cout << "Top element: " << myStack.top() << endl;
    }

    return 0;
}
