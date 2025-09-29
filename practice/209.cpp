#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT_MAX;
        int i = 0;
        int j = 0;
        int currentSum = nums[0];
        if (currentSum >= target)
            return 1;
        while (j < nums.size())
        {
            if (currentSum < target)
            {
                if (j + 1 < nums.size())
                {
                    currentSum += nums[++j];
                }
                else
                {
                    j++;
                }
            }
            else
            {
                result = min(result, j - i + 1);
                currentSum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main()
{
    Solution sln;
    int target;
    vector<int> nums;
    cout << sln.minSubArrayLen(target = 7, nums = {2, 3, 1, 2, 4, 3}) << endl;
    cout << sln.minSubArrayLen(target = 4, nums = {1, 4, 4}) << endl;
    cout << sln.minSubArrayLen(target = 11, nums = {1, 1, 1, 1, 1, 1, 1, 1}) << endl;
    return 0;
}