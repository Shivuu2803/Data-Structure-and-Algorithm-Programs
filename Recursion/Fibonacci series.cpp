#include <iostream>
using namespace std;

int fibonacci(int n) 
{
    // Base cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Recursive calls
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    int numTerms;

    cout << "Enter the number of terms: ";
    cin >> numTerms;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < numTerms; ++i)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
