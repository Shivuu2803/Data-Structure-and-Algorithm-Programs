#include <iostream>
#include <cmath>
using namespace std;

double squareRoot(double x, double epsilon = 0.00001) 
{
    if (x < 0)
        return -1.0; // Error: Square root of a negative number

    if (x == 0 || x == 1)
        return x;

    double left = 0.0;
    double right = x;
    double mid = (left + right) / 2;

    while (abs(mid * mid - x) > epsilon) 
    {
        if (mid * mid > x)
            right = mid;
        else
            left = mid;

        mid = (left + right) / 2;
    }

    return mid;
}

int main() 
{
    double number = 25.0;
    double result = squareRoot(number);

    cout << "Square root of " << number << " is: " << result << endl;

    return 0;
}
