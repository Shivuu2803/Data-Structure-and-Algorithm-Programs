#include <iostream>
#include <cmath>
using namespace std;

double getFractionalPart(double num) 
{
    double integralPart;
    double fractionalPart = modf(num, &integralPart);

    return fractionalPart;
}

int main() 
{
    double number = 10.5;
    double squareRoot = sqrt(number);
    double fractionalPart = getFractionalPart(squareRoot);

    cout << "Square root of " << number << " is: " << squareRoot << endl;
    cout << "Fractional part: " << fractionalPart << endl;

    return 0;
}
