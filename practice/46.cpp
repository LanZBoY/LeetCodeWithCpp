#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtracking(vector<int> &current, vector<int> &nums, vector<bool> &visited, vector<vector<int>> &res)
    {
        if (current.size() == nums.size())
        {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                current.push_back(nums[i]);
                backtracking(current, nums, visited, res);
                current.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> current;
        backtracking(current, nums, visited, res);
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    vector<vector<int>> res;
    res = sln.permute(nums = {1, 2, 3});
    return 0;
}