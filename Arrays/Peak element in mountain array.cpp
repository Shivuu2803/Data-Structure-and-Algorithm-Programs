#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) 
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) 
        {
            // The peak element is on the right side
            left = mid + 1;
        } else 
        {
            // The peak element is on the left side or mid is the peak
            right = mid;
        }
    }

    // Return the peak element index
    return left;
}

int main() 
{
    vector<int> nums = {1, 3, 5, 9, 7, 4, 2};

    int peakIndex = findPeakElement(nums);
    int peakValue = nums[peakIndex];

    cout << "Peak Element: " << peakValue << endl;
    cout << "Peak Index: " << peakIndex << endl;

    return 0;
}
