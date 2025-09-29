#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(int c_index, vector<int> &nums)
    {
        if (c_index >= nums.size() - 1)
            return true;
        int curNum = nums[c_index];
        while (curNum)
        {
            if (canJump(c_index + curNum, nums))
            {
                return true;
            }
            curNum--;
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        return canJump(0, nums);
    }
};

int main()
{
    vector<int> nums;
    Solution sln;

    cout << sln.canJump(nums = {2, 3, 1, 1, 4}) << endl;
    cout << sln.canJump(nums = {3, 2, 1, 0, 4}) << endl;
    return 0;
}