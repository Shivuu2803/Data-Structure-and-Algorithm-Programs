#include <iostream>
using namespace std;

int climbStairs(int n) 
{
    if (n <= 1)
    {
         return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    // Recursive calls
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() 
{
    int numStairs;

    cout << "Enter the number of stairs: ";
    cin >> numStairs;

    int numWays = climbStairs(numStairs);

    cout << "Number of ways to climb " << numStairs << " stairs: " << numWays << endl;

    return 0;
}
