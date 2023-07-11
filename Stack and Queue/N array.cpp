#include <iostream>
#include <vector>
using namespace std;

class NStack 
{
private:
    int numStacks;              // Number of stacks
    int stackCapacity;          // Capacity of each stack
    vector<int> arr;       // Array to hold the stack elements
    vector<int> stackTops; // Array to hold the top index of each stack

public:
    NStack(int n, int capacity) : numStacks(n), stackCapacity(capacity) 
    {
        arr.resize(n * capacity);
        stackTops.resize(n, -1);
    }

    bool isFull(int stackNum) const 
    {
        return stackTops[stackNum] == (stackNum + 1) * stackCapacity - 1;
    }

    bool isEmpty(int stackNum) const 
    {
        return stackTops[stackNum] == -1;
    }

    void push(int stackNum, int value) 
    {
        if (isFull(stackNum)) {
            cout << "Stack " << stackNum << " is full. Cannot push element.\n";
            return;
        }

        stackTops[stackNum]++;
        arr[getTopIndex(stackNum)] = value;
    }

    int pop(int stackNum) 
    {
        if (isEmpty(stackNum)) 
        {
            cout << "Stack " << stackNum << " is empty. Cannot pop element.\n";
            return -1;
        }

        int topIndex = getTopIndex(stackNum);
        int topValue = arr[topIndex];
        stackTops[stackNum]--;
        return topValue;
    }

    int top(int stackNum) const 
    {
        if (isEmpty(stackNum)) 
        {
            cout << "Stack " << stackNum << " is empty.\n";
            return -1;
        }

        return arr[getTopIndex(stackNum)];
    }

private:
    int getTopIndex(int stackNum) const 
    {
        return stackNum * stackCapacity + stackTops[stackNum];
    }
};

int main()
{
    int numStacks = 3;
    int stackCapacity = 5;

    NStack nStack(numStacks, stackCapacity);

    nStack.push(0, 10);
    nStack.push(0, 20);
    nStack.push(1, 30);
    nStack.push(2, 40);
    nStack.push(2, 50);

    cout << "Top of stack 0: " << nStack.top(0) << endl;
    cout << "Top of stack 1: " << nStack.top(1) << endl;
    cout << "Top of stack 2: " << nStack.top(2) << endl;

    nStack.pop(0);
    nStack.pop(1);
    nStack.pop(2);

    cout << "Top of stack 0: " << nStack.top(0) << endl;
    cout << "Top of stack 1: " << nStack.top(1) << endl;
    cout << "Top of stack 2: " << nStack.top(2) << endl;

    return 0;
}

