#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    int checkExist(long long num, unordered_map<long long, int> &existNumMap)
    {
        long long nextNum = num * num;
        if (existNumMap.count(nextNum) == 0)
        {
            return existNumMap[num] = 1;
        }
        if (existNumMap[num] != 0)
        {
            return existNumMap[num];
        }
        return existNumMap[num] = 1 + checkExist(nextNum, existNumMap);
    }

public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_map<long long, int> existNumMap;
        for (int &num : nums)
            existNumMap[num];
        int maxlen = 0;
        for (int &num : nums)
        {
            maxlen = max(maxlen, checkExist(num, existNumMap));
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