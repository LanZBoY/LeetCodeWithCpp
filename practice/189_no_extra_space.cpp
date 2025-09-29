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
        int reverse_i = nums.size() - k;
        for (int i = 0; i < reverse_i / 2; i++)
        {
            int tmp = nums[i];
            nums[i] = nums[reverse_i - i - 1];
            nums[reverse_i - i - 1] = tmp;
        }
        for (int i = reverse_i; i < (reverse_i + nums.size()) / 2; i++)
        {
            int tmp = nums[i];
            nums[i] = nums[nums.size() + (reverse_i - i) - 1];
            nums[nums.size() + (reverse_i - i) - 1] = tmp;
        }
        for (int i = 0; i < nums.size() / 2; ++i)
        {
            int tmp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = tmp;
        }
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    sln.rotate(nums = {1, 2, 3, 4, 5}, k = 4);
    sln.rotate(nums = {1, 2, 3, 4, 5, 6, 7}, k = 3);
    sln.rotate(nums = {-1, -100, 3, 99}, k = 2);
    return 0;
}