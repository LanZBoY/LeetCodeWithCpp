#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> LIS(nums.size(), 1);
        vector<int> LDS(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i;
            int right = nums.size() - i - 1;
            for (int j = 0; j < left; j++)
            {
                if (nums[left] > nums[j])
                {
                    LIS[left] = max(LIS[left], LIS[j] + 1);
                }
            }
            for (int j = nums.size() - 1; j > right; j--)
            {
                if (nums[right] > nums[j])
                {
                    LDS[right] = max(LDS[right], LDS[j] + 1);
                }
            }
        }
        int minRemoveCount = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (LIS[i] > 1 && LDS[i] > 1)
                minRemoveCount = min(minRemoveCount, ((int)nums.size()) - (LIS[i] + LDS[i] - 1));
        }
        return minRemoveCount;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.minimumMountainRemovals(nums = {9, 8, 1, 7, 6, 5, 4, 3, 2, 1}) << endl;
    // cout << sln.minimumMountainRemovals(nums = {1, 3, 1}) << endl;
    // cout << sln.minimumMountainRemovals(nums = {2, 1, 1, 5, 6, 2, 3, 1}) << endl;
    return 0;
}