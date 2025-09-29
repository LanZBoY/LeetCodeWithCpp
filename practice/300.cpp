#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxResult = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int maxNum = INT_MIN;
            for (int j = i - 1; j > -1; j--)
            {
                if (nums[i] > nums[j])
                {
                    maxNum = max(maxNum, dp[j]);
                }
            }
            if (maxNum != INT_MIN)
                dp[i] = maxNum + 1;
            maxResult = max(maxResult, dp[i]);
        }
        return maxResult;
    }
};

int main()
{
    vector<int> nums;
    Solution sln;
    cout << sln.lengthOfLIS(nums = {10, 9, 2, 5, 3, 7, 101, 18}) << endl;
    cout << sln.lengthOfLIS(nums = {0, 1, 0, 3, 2, 3}) << endl;
    cout << sln.lengthOfLIS(nums = {7, 7, 7, 7, 7, 7, 7}) << endl;
    return 0;
}