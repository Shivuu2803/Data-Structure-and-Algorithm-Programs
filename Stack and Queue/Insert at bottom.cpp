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

int main() 
{
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack before inserting at the bottom: ";

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

    int elementToInsert = 50;
    insertAtBottom(myStack, elementToInsert);

    cout << "Stack after inserting " << elementToInsert << " at the bottom: ";
    while (!myStack.empty()) 
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
