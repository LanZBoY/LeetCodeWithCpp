#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int jump(int position, vector<int> &nums, vector<int> &memo)
    {
        if (position == nums.size() - 1)
            return memo[position] = 0;
        if (nums[position] == 0)
            return 1e5;
        if (memo[position] != -1)
            return memo[position];
        int maxMove = nums.size() - position - 1;
        int res = 1 + jump(position + min(maxMove, nums[position]), nums, memo);
        for (int i = nums[position] - 1; i > 0; i--)
        {
            res = min(res, 1 + jump(position + min(i, maxMove), nums, memo));
        }
        return memo[position] = res;
    }

public:
    int jump(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        int res = jump(0, nums, memo);
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.jump(nums = {1, 3, 2}) << endl;
    cout << sln.jump(nums = {2, 3, 1, 1, 4}) << endl;
    cout << sln.jump(nums = {2, 3, 0, 1, 4}) << endl;
    return 0;
}