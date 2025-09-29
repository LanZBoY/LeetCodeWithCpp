#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int lower = 1;
    int higher = n - 2;
    while (lower <= higher)
    {
        int mid = (lower + higher) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        if (nums[mid] > nums[mid - 1])
        {
            lower = mid + 1;
        }
        else
        {
            higher = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums;

    nums = {1, 2, 1};
    cout << findPeakElement(nums) << endl;

    nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;

    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums) << endl;

    nums = {1};
    cout << findPeakElement(nums) << endl;

    nums = {3, 2, 1};
    cout << findPeakElement(nums) << endl;

    return 0;
}