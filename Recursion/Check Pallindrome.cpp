#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) 
{
    // Base case: If start becomes greater than or equal to end, the string is a palindrome
    if (start >= end)
        return true;

    // Convert characters to lowercase for case-insensitive comparison
    char left = tolower(str[start]);
    char right = tolower(str[end]);

    // If the characters at start and end indices are equal, continue checking the remaining substring
    if (left == right)
        return isPalindrome(str, start + 1, end - 1);

    // If the characters are not equal, the string is not a palindrome
    return false;
}

bool checkPalindrome(const string& str) 
{
    int start = 0;
    int end = str.length() - 1;

    return isPalindrome(str, start, end);
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin>> str;

    if (checkPalindrome(str))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
         cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
