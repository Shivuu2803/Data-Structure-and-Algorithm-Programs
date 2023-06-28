#include <iostream>
using namespace std;

double power(double base, int exponent) 
{
    // Base case: If the exponent is 0, the result is 1
    if (exponent == 0)
        return 1;

    // Recursive case: Multiply the base by the result of the recursive call with a reduced exponent
    if (exponent > 0)
        return base * power(base, exponent - 1);
    else
        return (1 / base) * power(base, exponent + 1);
}

int main() {
    double base;
    int exponent;

    cout << "Enter the base number: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = power(base, exponent);

    cout << "Result: " << result << endl;

    return 0;
}
