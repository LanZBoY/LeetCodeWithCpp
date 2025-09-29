#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int *find_low_bound(vector<int> &orderSeq, int num)
    {
        int i = 0;
        int j = orderSeq.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (orderSeq[mid] == num)
                return &orderSeq[mid];
            if (orderSeq[mid] < num)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return &orderSeq[i];
    }
    vector<int> getLIS(vector<int> &nums)
    {
        vector<int> LIS(nums.size(), 0);
        vector<int> tempSeq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tempSeq.empty() || tempSeq.back() < nums[i])
            {
                tempSeq.push_back(nums[i]);
            }
            else
            {
                int *target = find_low_bound(tempSeq, nums[i]);
                *target = nums[i];
            }
            LIS[i] = tempSeq.size();
        }
        return LIS;
    }

public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> LIS = getLIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> LDS = getLIS(nums);
        reverse(LDS.begin(), LDS.end());
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
    cout << sln.minimumMountainRemovals(nums = {1, 3, 1}) << endl;
    cout << sln.minimumMountainRemovals(nums = {2, 1, 1, 5, 6, 2, 3, 1}) << endl;
    return 0;
}