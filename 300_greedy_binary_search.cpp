#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int find_low_bound(int num, vector<int> &curSeq)
    {
        int i = 0;
        int j = curSeq.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (curSeq[mid] == num)
                return mid;

            if (curSeq[mid] < num)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return i;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> curSeq;
        for (int num : nums)
        {
            if (curSeq.empty() || num > curSeq.back())
            {
                curSeq.push_back(num);
            }
            else
            {
                // do bs to find where curSeq[i] >= x and replace it.
                int index = find_low_bound(num, curSeq);
                curSeq[index] = num;
            }
        }
        return curSeq.size();
    }
};

int main()
{
    vector<int> nums;
    Solution sln;
    cout << sln.lengthOfLIS(nums = {2, 6, 8, 3, 4, 5, 1}) << endl;
    // cout << sln.lengthOfLIS(nums = {10, 9, 2, 5, 3, 7, 101, 18}) << endl;
    // cout << sln.lengthOfLIS(nums = {0, 1, 0, 3, 2, 3}) << endl;
    // cout << sln.lengthOfLIS(nums = {7, 7, 7, 7, 7, 7, 7}) << endl;
    return 0;
}