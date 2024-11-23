#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool hasValidSubArray(vector<int> &nums, int &k, int &windowSize)
    {
        int arrlength = nums.size();
        vector<int> bitCounts(32, 0);
        for (int i = 0; i < arrlength; i++)
        {
            updateBitCouints(bitCounts, nums[i], 1);

            if (i >= windowSize)
            {
                updateBitCouints(bitCounts, nums[i - windowSize], -1);
            }

            if (i >= windowSize - 1 && covertBitCountsToNumber(bitCounts) >= k)
            {
                return true;
            }
        }
        return false;
    }

    void updateBitCouints(vector<int> &bitCounts, int number, int delta)
    {
        for (int position = 0; position < 32; position++)
        {
            if ((number >> position) & 1 != 0)
            {
                bitCounts[position] += delta;
            }
        }
    }

    int covertBitCountsToNumber(vector<int> &bitCounts)
    {
        int num = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bitCounts[i] != 0)
            {
                num = num | (1 << i);
            }
        }
        return num;
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int left = 1;
        int right = nums.size();
        int minLength = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (hasValidSubArray(nums, k, mid))
            {
                minLength = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return minLength;
    }
};

int main()
{
    vector<int> nums;
    int k;
    Solution sln;
    cout << sln.minimumSubarrayLength(nums = {1, 2, 3}, k = 2) << endl;
    cout << sln.minimumSubarrayLength(nums = {2, 1, 8}, k = 10) << endl;
    cout << sln.minimumSubarrayLength(nums = {1, 2}, k = 0) << endl;
    return 0;
}