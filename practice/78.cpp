#include <iostream>
#include <vector>

using namespace std;

void subsets(vector<vector<int>> &results, vector<int> currentSet, int i, vector<int> &nums)
{
    results.push_back(currentSet);
    for (int j = i; j < nums.size(); j++)
    {
        currentSet.push_back(nums[j]);
        subsets(results, currentSet, j + 1, nums);
        currentSet.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> results;
    subsets(results, {}, 0, nums);
    return results;
}

int main()
{
    vector<int> nums;
    vector<vector<int>> results;
    nums = {1, 2, 3};
    results = subsets(nums);
    return 0;
}