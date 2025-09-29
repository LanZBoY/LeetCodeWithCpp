#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> calMap;
        calMap[nums[0] - 0] = 1;
        long long total = 1;
        long long count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            count += (total - calMap[nums[i] - i]);
            calMap[nums[i] - i] += 1;
            total += 1;
        }
        return count;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.countBadPairs(nums = {4, 1, 3, 3}) << endl;
    cout << sln.countBadPairs(nums = {1, 2, 3, 4}) << endl;
    return 0;
}