#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int near = 0;
        int far = 0;
        int jumps = 0;
        while (far < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = near; i <= far; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.jump(nums = {2, 3, 1, 1, 4}) << endl;
    cout << sln.jump(nums = {2, 3, 0, 1, 4}) << endl;
    cout << sln.jump(nums = {1, 3, 2}) << endl;
    return 0;
}