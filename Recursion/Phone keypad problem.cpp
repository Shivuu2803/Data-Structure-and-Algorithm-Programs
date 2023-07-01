#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> keypad = 
{
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Utility function to generate all possible letter combinations from a phone keypad
void generatePhoneKeypadWordsUtil(int number[], int current_digit, string output, int n) 
{
    // Base case: If we have processed all digits, print the output
    if (current_digit == n) 
    {
        cout << output << " ";
        return;
    }

    // Get the letters corresponding to the current digit
    string letters = keypad[number[current_digit]];

    // Iterate through each letter and make recursive calls
    for (int i = 0; i < letters.size(); i++) 
    {
        generatePhoneKeypadWordsUtil(number, current_digit + 1, output + letters[i], n);
    }
}

// Function to generate all possible letter combinations from a given array of digits
void generatePhoneKeypadWords(int number[], int n) 
{
    generatePhoneKeypadWordsUtil(number, 0, "", n);
}

int main() 
{
    int number[] = {2, 3, 4}; // Example input digits

    int n = sizeof(number) / sizeof(number[0]);

    generatePhoneKeypadWords(number, n);
  
    return 0;
}
