#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string& str) 
{
    stack<char> charStack;

    // Push each character of the string onto the stack
    for (char c : str) 
    {
        charStack.push(c);
    }

    string reversedStr;

    // Pop each character from the stack to reverse the order
    while (!charStack.empty()) 
    {
        reversedStr += charStack.top();
        charStack.pop();
    }

    return reversedStr;
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string reversed = reverseString(str);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
