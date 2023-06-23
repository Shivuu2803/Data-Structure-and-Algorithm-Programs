#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    int first = -1;
    int last = -1;

    // Find the first occurrence of the target element
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) 
        {
            first = mid;
            right = mid - 1;
        } else if (nums[mid] < target)
        {
            left = mid + 1;
        } else 
        {
            right = mid - 1;
        }
    }

    // If the target element is not found, return [-1, -1]
    if (first == -1) 
    {
        return {-1, -1};
    }

    // Find the last occurrence of the target element
    left = first;
    right = nums.size() - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) 
        {
            last = mid;
            left = mid + 1;
        } else if (nums[mid] < target) 
        {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {first, last};
}

int main() 
{
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    int target = 3;

    vector<int> positions = searchRange(nums, target);

    cout << "First position: " << positions[0] << std::endl;
    cout << "Last position: " << positions[1] << std::endl;

    return 0;
}
