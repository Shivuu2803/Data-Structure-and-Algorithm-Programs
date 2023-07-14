#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParentheses(string& str) 
{
    stack<char> parenStack;

    for (char c : str) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            parenStack.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (parenStack.empty()) 
            {
                return false;  // Closing parenthesis without a corresponding opening parenthesis
            }

            char top = parenStack.top();
            parenStack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
            {
                return false;  // Mismatched opening and closing parentheses
            }
        }
    }

    return parenStack.empty();  // Stack should be empty if all parentheses are matched
}

int main() 
{
    string str;
    cout << "Enter a string with parentheses: ";
    cin >> str;

    if (isValidParentheses(str)) 
    {
        cout << "Parentheses are valid." << endl;
    } 
    else 
    {
        cout << "Parentheses are not valid." << endl;
    }

    return 0;
}
