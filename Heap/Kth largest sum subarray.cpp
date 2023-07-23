#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Subarray 
{
public:
    int sum;
    int start;
    int end;

    Subarray(int s, int e, int sm) 
    {
        this->start = s;
        this->end = e;
        this->sum = sm;
    }
};

// Comparator function to compare two Subarray objects based on sum
class CompareSubarray 
{
public:
    bool operator()(const Subarray& a, const Subarray& b) const
    {
        return a.sum > b.sum;  // Min heap based on sum
    }
};

// Function to find the Kth largest sum subarray
int findKthLargestSumSubarray(const std::vector<int>& arr, int K) 
{
    int n = arr.size();

    // Priority queue (min heap) to store the K largest sum subarrays
    priority_queue<Subarray, std::vector<Subarray>, CompareSubarray> pq;

    // Calculate the prefix sum of the array
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    // Find all possible subarrays and keep track of the K largest sums
    for (int i = 0; i <= n; i++) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            int sum = prefixSum[j] - prefixSum[i];
            if (pq.size() < K)
            {
                pq.push(Subarray(i, j - 1, sum));
            }
            else if (sum > pq.top().sum) 
            {
                pq.pop();
                pq.push(Subarray(i, j - 1, sum));
            }
        }
    }

    // The top of the min heap will have the Kth largest sum subarray
    return pq.top().sum;
}

int main() 
{
    vector<int> arr = {10, -4, 3, 1, 5};
    int K = 3;

    int kthLargestSum = findKthLargestSumSubarray(arr, K);

    cout << "Kth largest sum subarray: " << kthLargestSum << endl;

    return 0;
}
