#include <iostream>
using namespace std;

void sayDigit(int number) 
{
    const char* digitWords[] = 
    {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    if (number < 10) 
    {
        cout << digitWords[number] << " ";
        return;
    }

    sayDigit(number / 10);    // Recursively say the digits except the last one
    cout << digitWords[number % 10] << " "; // Say the last digit as word
}

int main() 
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Digits as words: ";
    sayDigit(num);

    return 0;
}
