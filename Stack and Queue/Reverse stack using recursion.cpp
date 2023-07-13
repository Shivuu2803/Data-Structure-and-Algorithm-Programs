#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& stack, int element) 
{
    if (stack.empty()) 
    {
        stack.push(element);
        return;
    }

    int top = stack.top();
    stack.pop();

    insertAtBottom(stack, element);

    stack.push(top);
}

void reverseStack(stack<int>& stack) 
{
    if (stack.empty()) 
    {
        return;
    }

    int top = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, top);
}

int main() 
{
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack before reversing: ";
    while (!myStack.empty()) 
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Repopulate the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    reverseStack(myStack);

    cout << "Stack after reversing: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
