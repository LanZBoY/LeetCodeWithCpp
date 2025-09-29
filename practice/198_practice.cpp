#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> nums, int currentIndex)
{
    if (nums.empty())
        return 0;
    if (currentIndex < 0)
        return 0;
    if (currentIndex == 0)
        return nums[currentIndex];
    return max(nums[currentIndex] + solve(nums, currentIndex - 2), solve(nums, currentIndex - 1));
}

int solve_memo(vector<int> nums, vector<int> &result, int currentIndex)
{
    if (nums.empty())
        return 0;
    if (currentIndex < 0)
        return 0;
    if (result[currentIndex] != -1)
        return result[currentIndex];
    if (currentIndex == 0)
    {
        result[currentIndex] = nums[currentIndex];
        return nums[currentIndex];
    }
    result[currentIndex] = max(nums[currentIndex] + solve_memo(nums, result, currentIndex - 2), solve_memo(nums, result, currentIndex - 1));
    return result[currentIndex];
}

int rob(vector<int> &nums)
{
    vector<int> results(nums.size(), -1);
    return solve_memo(nums, results, nums.size() - 1);
}

int main()
{
    vector<int> nums;

    nums = {1, 2, 3, 1};
    cout << rob(nums) << endl;

    nums = {2, 1, 1, 2};
    cout << rob(nums) << endl;

    nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}