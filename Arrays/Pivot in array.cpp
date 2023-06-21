#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) 
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) 
        {
            // The pivot element is in the right half
            left = mid + 1;
        } else 
        {
            // The pivot element is in the left half or mid is the pivot
            right = mid;
        }
    }

    // Return the pivot element
    return nums[left];
}

int main() 
{
    vector<int> nums = {4, 5, 6, 7, 1, 2};

    int pivot = findPivot(nums);

    cout << "Pivot Element: " << pivot << endl;

    return 0;
}
