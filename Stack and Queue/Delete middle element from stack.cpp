#include <iostream>
#include <stack>
using namespace std;

void deleteMiddleElement(stack<int>& stack) 
{
    int size = stack.size();
    int middle = size / 2;

    std::stack<int> tempStack;

    // Pop and store elements from the original stack until the middle element
    for (int i = 0; i < middle; i++) 
    {
        tempStack.push(stack.top());
        stack.pop();
    }

    // Skip the middle element
    stack.pop();

    // Push back the elements stored in the temporary stack
    while (!tempStack.empty()) 
    {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() 
{
    stack<int> myStack;

    // Push some elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Before deletion: ";

    stack<int> tempStack = myStack;    // Create a copy for printing stack 

    while (!tempStack.empty()) 
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Delete the middle element
    deleteMiddleElement(myStack);

    cout << "After deletion: ";

    while (!myStack.empty()) 
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
