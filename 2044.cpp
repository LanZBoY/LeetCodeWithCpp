#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int backtracking(int current, int current_i, int &maximum, vector<int> &nums)
    {

        int count = 0;
        if (current == maximum)
            count++;
        for (int i = current_i; i < nums.size(); ++i)
        {
            count += backtracking(current | nums[i], i + 1, maximum, nums);
        }
        return count;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maximum = 0;
        for (int &num : nums)
            maximum = maximum | num;
        vector<bool> visited(nums.size(), false);
        return backtracking(0, 0, maximum, nums);
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.countMaxOrSubsets(nums = {3, 1}) << endl;
    cout << sln.countMaxOrSubsets(nums = {2, 2, 2}) << endl;
    cout << sln.countMaxOrSubsets(nums = {3, 2, 1, 5}) << endl;
    return 0;
}