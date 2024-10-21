#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int canReach = 0;
        for (int i = 0; i < nums.size() && canReach < nums.size(); ++i)
        {
            if (i <= canReach)
            {
                canReach = max(canReach, i + nums[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.canJump(nums = {2, 3, 1, 1, 4});
    cout << sln.canJump(nums = {3, 2, 1, 0, 4});
    return 0;
}