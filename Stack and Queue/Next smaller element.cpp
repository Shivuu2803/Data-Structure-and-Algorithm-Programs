#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNextSmallerElement(const vector<int>& arr) 
{
    vector<int> result(arr.size(), -1);
    stack<int> stk;

    for (int i = 0; i < arr.size(); i++) 
    {
        while (!stk.empty() && arr[stk.top()] > arr[i]) 
        {
            result[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    return result;
}

int main() 
{
    vector<int> arr = {4, 8, 2, 1, 5, 10};
    vector<int> nextSmaller = findNextSmallerElement(arr);

    cout << "Array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next smaller element for each element: ";
    for (int num : nextSmaller) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
