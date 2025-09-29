#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canReach(int c_index, vector<int> &nums)
    {
        if (c_index <= 0)
            return true;
        for (int i = c_index - 1; i >= 0; --i)
        {
            if (nums[i] + i >= c_index)
            {
                return canReach(i, nums);
            }
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        int lastIndex = nums.size() - 1;
        return canReach(lastIndex, nums);
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