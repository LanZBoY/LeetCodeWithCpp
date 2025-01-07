#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int dp(vector<int> &sums, int k, int idx, int rem,
           vector<vector<int>> &memo)
    {
        if (rem == 0)
            return 0;
        if (idx >= sums.size())
        {
            return rem > 0 ? INT_MIN : 0;
        }

        if (memo[idx][rem] != -1)
        {
            return memo[idx][rem];
        }
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);
        memo[idx][rem] = max(withCurrent, skipCurrent);
        return memo[idx][rem];
    }

    void dfs(vector<int> &sums, int k, int idx, int rem,
             vector<vector<int>> &memo, vector<int> &indices)
    {
        if (rem == 0)
            return;
        if (idx >= sums.size())
            return;

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent)
        { // Take current subarray
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        }
        else
        { // Skip current subarray
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size() - k + 1;
        vector<int> sums(n);
        int windowSum = 0;
        for (int i = 0; i < k; i++)
        {
            windowSum += nums[i];
        }
        sums[0] = windowSum;
        for (int i = k; i < nums.size(); i++)
        {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        vector<vector<int>> memo(n, vector<int>(4, -1));
        dp(sums, k, 0, 3, memo);

        vector<int> indices;
        dfs(sums, k, 0, 3, memo, indices);
        return indices;
    }
};

int main()
{
    Solution sln;
    vector<int> result;
    vector<int> nums;
    int k;
    result = sln.maxSumOfThreeSubarrays(nums = {1, 2, 1, 2, 6, 7, 5, 1}, k = 2);
    result = sln.maxSumOfThreeSubarrays(nums = {1, 2, 1, 2, 1, 2, 1, 2, 1}, k = 2);
    return 0;
}