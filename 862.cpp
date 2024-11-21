#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        vector<int> prefixSum(nums.size() + 1, 0);
        int minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            for (int j = i; j >= 0; j--)
            {
                if (prefixSum[i + 1] - prefixSum[j] >= k)
                {
                    minLen = min(minLen, i - j + 1);
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    // cout << sln.shortestSubarray(nums = {1}, k = 1) << endl;
    // cout << sln.shortestSubarray(nums = {1, 2}, k = 4) << endl;
    cout << sln.shortestSubarray(nums = {2, -1, 2}, k = 3) << endl;
    return 0;
}