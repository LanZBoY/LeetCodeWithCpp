#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    // {1, 2, 3, 1};
    // n(0), nums[0]
    // n(1), nums[1]
    // n(2), max(nums[2] + n(n-2), n(n-1)) => nums[2] + nums[0]
    // n(3), max(nums[3] + n(n-2), n(n - 1))

    if (nums.size() == 1)
    {
        return nums[0];
    }
    else if (nums.size() == 2)
    {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    vector<int> results(nums.size());
    results[0] = nums[0];
    results[1] = max(nums[1], results[0]);
    for (int i = 2; i < results.size(); i++)
    {
        results[i] = max(nums[i] + results[i - 2], results[i - 1]);
    }
    return results[results.size() - 1];
}

int main()
{
    vector<int> nums;
    nums = {2, 1, 1, 2};
    cout << rob(nums) << endl;

    nums = {1, 2, 3, 1};
    cout << rob(nums) << endl;
    nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}