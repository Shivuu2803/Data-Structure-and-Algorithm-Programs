#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    for(int i=0; i<arr.size(); i++)
    {
        count[arr[i]]++;
    }

    int maxi = INT_MIN;
    int ans = -1;

    for(auto i:count)
    {
        if(i.second > maxi)
        {
            maxi = i.second;
            ans = i.first;
            ans = i.first;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3};
    int n = arr.size();

    int result = maximumFrequency(arr, n);

    cout << "Element with maximum frequency: " << result << endl;

    return 0;



}
