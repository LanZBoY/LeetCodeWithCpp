#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reach = 0;
        for (int i = 0; i <= reach; i++)
        {
            reach = max(reach, i + nums[i]);
            if (reach >= nums.size() - 1)
                return true;
        }
        return false;
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