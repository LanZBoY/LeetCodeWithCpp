#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
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
        int i = 0;
        int j = 0;
        int minLength = INT_MAX;
        vector<int> bitCounts(32, 0);

        while (j < nums.size())
        {
            updateBitCouints(bitCounts, nums[j], 1);
            while (i <= j && covertBitCountsToNumber(bitCounts) >= k)
            {
                minLength = min(minLength, j - i + 1);

                updateBitCouints(bitCounts, nums[i], -1);
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? -1 : minLength;
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