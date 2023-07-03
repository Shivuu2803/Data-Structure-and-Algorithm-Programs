#include <iostream>
using namespace std;

void findSubsequence(string str, string curr, int index)
{
    // Base case: If we have reached the end of the string
    if (index == str.length()) 
    {
        // Print the current subsequence
        cout << curr << " ";
        return;
    }

    // Recursive case 1: Include the current character
    findSubsequence(str, curr + str[index], index + 1);

    // Recursive case 2: Exclude the current character
    findSubsequence(str, curr, index + 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Subsequences of the string: ";
    findSubsequence(str, "", 0);

    return 0;
}
