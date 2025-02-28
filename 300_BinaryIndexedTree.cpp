#include <iostream>
#include <vector>

using namespace std;

class MaxBIT
{ // One-based indexing
    vector<int> bit;

public:
    MaxBIT(int size)
    {
        bit.resize(size + 1);
    }
    int get(int idx)
    {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val)
    {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
};
class Solution
{ // 16 ms, faster than 72.16%
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int BASE = 10001;
        MaxBIT bit(20001);
        for (int x : nums)
        {
            int subLongest = bit.get(BASE + x - 1);
            bit.update(BASE + x, subLongest + 1);
        }
        return bit.get(20001);
    }
};

int main()
{
    vector<int> nums;
    Solution sln;
    cout << sln.lengthOfLIS(nums = {2, 6, 8, 3, 4, 5, 1}) << endl;
    cout << sln.lengthOfLIS(nums = {10, 9, 2, 5, 3, 7, 101, 18}) << endl;
    cout << sln.lengthOfLIS(nums = {0, 1, 0, 3, 2, 3}) << endl;
    cout << sln.lengthOfLIS(nums = {7, 7, 7, 7, 7, 7, 7}) << endl;
    return 0;
}