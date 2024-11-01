#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    int checkExist(int num, unordered_set<int> &existNumSet)
    {
        int nextNum = num * num;
        if (existNumSet.count(nextNum) == 0)
            return 1;
        return 1 + checkExist(nextNum, existNumSet);
    }

public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_set<int> existNumSet(nums.begin(), nums.end());
        int maxlen = 0;
        for (int &num : nums)
        {
            maxlen = max(maxlen, checkExist(num, existNumSet));
        }
        return maxlen == 1 ? -1 : maxlen;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.longestSquareStreak(nums = {4, 3, 6, 16, 8, 2}) << endl;
    cout << sln.longestSquareStreak(nums = {2, 3, 5, 6, 7}) << endl;
    return 0;
}