#include <iostream>
#include <string>
#include <cctype>  //This line includes the cctype library, which contains functions for working with characters and testing their properties.
using namespace std;


bool isPalindrome(string& str) 
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right) 
    {
        while (left < right && !isalnum(str[left]))  //isalnum is a function used to check whether given character is is a alphanumeric or not.
        {
            left++;
        }
        while (left < right && !isalnum(str[right])) 
        {
            right--;
        }

        if (tolower(str[left]) != tolower(str[right])) 
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() 
{
    string str = "A man, a plan, a canal: Panama";

    if (isPalindrome(str)) 
    {
        cout << str << " is a valid palindrome." << endl;
    } else 
    {
        cout << str << " is not a valid palindrome." << endl;
    }

    return 0;
}
