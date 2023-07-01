#include <iostream>
#include <string>
using namespace std;

void swap(char& a, char& b) 
{
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(string str, int left, int right) 
{
    // Base case: If we have reached the end of the string
    if (left == right) 
    {
        cout << str << " ";
        return;
    }

    // Recursive case: Generate permutations by swapping characters
    for (int i = left; i <= right; i++) 
    {
        swap(str[left], str[i]);
        generatePermutations(str, left + 1, right);
        swap(str[left], str[i]); // Backtracking
    }
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Permutations of the string: ";
    generatePermutations(str, 0, str.length() - 1);

    return 0;
}
