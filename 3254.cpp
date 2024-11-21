#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> results(nums.size() - k + 1, 0);
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            int maxVal = nums[i];
            for (int j = i + 1; j < i + k; j++)
            {
                maxVal = max(maxVal, nums[j]);
                if (nums[j] - nums[j - 1] != 1)
                {
                    results[i] = -1;
                    break;
                }
            }
            results[i] = results[i] == -1 ? results[i] : maxVal;
        }
        return results;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    vector<int> results;
    results = sln.resultsArray(nums = {1, 2, 3, 4, 3, 2, 5}, k = 3);
    results = sln.resultsArray(nums = {2, 2, 2, 2, 2}, k = 4);
    results = sln.resultsArray(nums = {3, 2, 3, 2, 3, 2}, k = 2);
    results = sln.resultsArray(nums = {1}, k = 1);
    return 0;
}