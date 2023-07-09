#include <iostream>
using namespace std;

class TwoStacks 
{
private:
    int* arr; // Array to store the elements
    int capacity; // Total capacity of the array
    int top1; // Top element index of the first stack
    int top2; // Top element index of the second stack

public:
    TwoStacks(int size) 
    {
        arr = new int[size];
        capacity = size;
        top1 = -1; // Initialize top1 for the first stack
        top2 = capacity; // Initialize top2 for the second stack
    }

    void push1(int element) 
    {
        if (top1 < top2 - 1) 
        {
            arr[++top1] = element;
            cout << "Element " << element << " pushed to Stack 1." << endl;
        } 
        else 
        {
            cout << "Stack Overflow! Cannot push element to Stack 1." << endl;
        }
    }

    void push2(int element) 
    {
        if (top1 < top2 - 1) 
        {
            arr[--top2] = element;
            cout << "Element " << element << " pushed to Stack 2." << endl;
        } 
        else 
        {
            cout << "Stack Overflow! Cannot push element to Stack 2." << endl;
        }
    }

    int pop1() 
    {
        if (top1 >= 0) 
        {
            int element = arr[top1--];
            return element;
        } 
        else 
        {
            cout << "Stack 1 is empty. Cannot pop element." << endl;
            return -1;
        }
    }

    int pop2() 
    {
        if (top2 < capacity)
        {
            int element = arr[top2++];
            return element;
        } 
        else
        {
            cout << "Stack 2 is empty. Cannot pop element." << endl;
            return -1;
        }
    }
};

int main() 
{
    TwoStacks stacks(6);

    stacks.push1(10);
    stacks.push2(20);
    stacks.push2(30);
    stacks.push1(40);
    stacks.push2(50);

    cout << "Popped element from Stack 1: " << stacks.pop1() << endl;
    cout << "Popped element from Stack 2: " << stacks.pop2() << endl;

    return 0;
}
