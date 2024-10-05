#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
            return;
        vector<int> tmp(nums.size(), 0);
        int rotated_bp = nums.size() - k;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = tmp[i];
        }
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    sln.rotate(nums = {1, 2, 3, 4, 5, 6, 7}, k = 3);
    sln.rotate(nums = {1, 2, 3, 4, 5}, k = 4);
    sln.rotate(nums = {-1, -100, 3, 99}, k = 2);
    return 0;
}