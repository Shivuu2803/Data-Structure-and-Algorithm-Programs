#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& s) 
{
    stack<int> tempStack;

    while (!s.empty()) 
    {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() < temp) 
        {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    s = tempStack;  // Update the original stack with the sorted elements
}

int main() 
{
    stack<int> myStack;
    myStack.push(5);
    myStack.push(3);
    myStack.push(8);
    myStack.push(1);
    myStack.push(2);

    cout << "Before sorting: ";

    stack<int> originalStack = myStack; // Create a copy of the original stack for printing
    
    while (!originalStack.empty()) 
    {
        cout << originalStack.top() << " ";
        originalStack.pop();
    }
    cout << endl;

    sortStack(myStack);

    cout << "After sorting: ";
    while (!myStack.empty()) 
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
