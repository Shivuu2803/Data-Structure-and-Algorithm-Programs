//Top down approcah 

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp)
{
    //base case
    if(n<=1)
    {
        return n;
    }

    //step 2
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];

    //step 3
    if(dp[n] != -1)
    {
        return dp[n];
    }
}

int main()
{
    int n;
    cout << "Enter value of n:" ;
    cin >> n;

    vector<int> dp(n+1);
    for(int i=0; i<=n; i++)
    {
        dp[i] = -1;
    }
    cout<< fib(n, dp) << endl;
}


//TABULATION CODE

// int main()
// {
//     int n;
//     cout << "Enter value of n:" ;
//     cin >> n;

//     vector<int> dp(n+1);
    
//     dp[1] = 1;
//     dp[0] = 0;

//     for(int i=2;i<=n;i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout<< dp[n] << endl;
// }

 
//Space optimization -> koi bhi number apne dono previous numbers ka sum hoga 

// int main()
// {
//     int n;
//     cout << "Enter value of n:" ;
//     cin >> n;

//     int prev1 = 1;
//     int prev2 = 0;

//     if(n==0)
//     {
//         return prev2;
//     }

//     for(int i =2; i<=n;i++)
//     {
//         int curr = prev1 + prev2;

//         //shift prev1 and 2
//         prev2 = prev1;
//         prev1 = curr;
//     }
//     cout << prev1 << endl;
// }

