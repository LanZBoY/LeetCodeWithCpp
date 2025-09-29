#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int maxLen = 1;
        int maxInLen = 1;
        int maxDeLen = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                maxInLen++;
                maxDeLen = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                maxDeLen++;
                maxInLen = 1;
            }
            else
            {
                maxInLen = 1;
                maxDeLen = 1;
            }
            maxLen = max(maxLen, max(maxInLen, maxDeLen));
        }
        return maxLen;
    }
};

int main(void)
{
    Solution sln;
    vector<int> nums;
    cout << sln.longestMonotonicSubarray(nums = {1, 4, 3, 3, 2}) << endl;
    cout << sln.longestMonotonicSubarray(nums = {3, 3, 3, 3}) << endl;
    cout << sln.longestMonotonicSubarray(nums = {3, 2, 1}) << endl;
    cout << sln.longestMonotonicSubarray(nums = {1, 1, 5}) << endl;
    return 0;
}