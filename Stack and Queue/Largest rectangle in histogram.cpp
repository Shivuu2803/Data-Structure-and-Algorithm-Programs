#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(const vector<int>& heights) 
{
    stack<int> stk;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size()) 
    {
        if (stk.empty() || heights[i] >= heights[stk.top()]) 
        {
            stk.push(i);
            i++;
        } 
        else 
        {
            int top = stk.top();
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            int area = heights[top] * width;
            maxArea = max(maxArea, area);
        }
    }

    while (!stk.empty()) 
    {
        int top = stk.top();
        stk.pop();
        int width = stk.empty() ? i : i - stk.top() - 1;
        int area = heights[top] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int largestArea = largestRectangleArea(heights);

    cout << "Heights: ";
    for (int height : heights) {
        cout << height << " ";
    }
    cout << endl;

    cout << "Largest Rectangle Area: " << largestArea << endl;

    return 0;
}
