#include <iostream>
#include <string>

using namespace std;

void generateSubsets(string str, int index = 0, string current = "") 
{
    if (index == str.length()) 
    {
        cout << current << endl;
        return;
    }

    // Include current character
    generateSubsets(str, index + 1, current + str[index]);

    // Exclude current character
    generateSubsets(str, index + 1, current);
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Subsets of the string are:" << endl;
    generateSubsets(str);

    return 0;
}
