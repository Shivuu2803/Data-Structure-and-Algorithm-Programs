#include <iostream>
#include <vector>
using namespace std;

// Function to sort a list of 0s, 1s, and 2s
void sort012(vector<int>& nums) 
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) 
    {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) 
        {
            mid++;
        } 
        else 
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Function to print the list
void printList(const std::vector<int>& nums) 
{
    for (const int& num : nums) 
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << "Original List: ";

    printList(nums);

    sort012(nums);
    cout << "Sorted List: ";

    printList(nums);

    return 0;
}
