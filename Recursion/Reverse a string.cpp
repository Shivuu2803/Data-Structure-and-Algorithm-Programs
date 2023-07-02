#include <iostream>
using namespace std;

void reverseString(string& str, int start, int end) 
{
    // Base case: If start becomes greater than or equal to end, the string is fully reversed
    if (start >= end)
    {
         return;
    }
    // Swap the characters at start and end indices
    swap(str[start], str[end]);

    // Recursively reverse the remaining substring
    reverseString(str, start + 1, end - 1);
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverseString(str, 0, str.length() - 1);

    cout << "Reversed string: " << str << std::endl;

    return 0;
}
