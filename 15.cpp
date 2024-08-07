#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    set<vector<int>> resultSet;
    for (int targetIndex = 0; targetIndex < nums.size(); targetIndex++)
    {
        int targetNum = -nums[targetIndex];
        int i = targetIndex + 1;
        int j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > targetNum)
            {
                j--;
                continue;
            }
            if (nums[i] + nums[j] + nums[targetIndex] == 0)
            {
                resultSet.insert({nums[targetIndex], nums[i], nums[j]});
            }
            i++;
        }
    }
    vector<vector<int>> results(resultSet.begin(), resultSet.end());

    return results;
}

int main()
{
    vector<int> data = {-1, 0, 1, 2, -1, -4};
    threeSum(data);
    data = {0, 1, 1};
    threeSum(data);
    data = {0, 0, 0};
    threeSum(data);
    return 0;
}