#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums, int start, int end)
{
    if (end < start)
        return -1;

    int mid = (start + end) / 2;

    if (mid + 1 < nums.size() && mid - 1 >= 0)
    {
        if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
            return mid;
    }
    else if (mid + 1 >= nums.size())
    {
        if (nums[mid - 1] < nums[mid])
            return mid;
    }
    else if (mid - 1 < 0)
    {
        if (nums[mid + 1] < nums[mid])
            return mid;
    }

    int result = findPeakElement(nums, start, mid - 1);
    if (result != -1)
    {
        return result;
    }
    return findPeakElement(nums, mid + 1, end);
}

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }
    int start = 0;
    int end = nums.size() - 1;
    return findPeakElement(nums, start, end);
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