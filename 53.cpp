#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int c_Max = nums[0];
        int totalMax = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            c_Max = max(curr, nums[i] + c_Max);
            totalMax = max(totalMax, c_Max);
        }
        return totalMax;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;

    cout << sln.maxSubArray(nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
    cout << sln.maxSubArray(nums = {1}) << endl;
    cout << sln.maxSubArray(nums = {5, 4, -1, 7, 8}) << endl;
    return 0;
}