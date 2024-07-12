#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> tempSet;
    sort(nums.begin(), nums.end());
    for (int targetIndex = 0; targetIndex < nums.size(); targetIndex++)
    {
        int target = -nums[targetIndex];
        int i = targetIndex + 1;
        int j = nums.size() - 1;
        while (i < j)
        {
            if (i == targetIndex || target > nums[i] + nums[j])
            {
                i++;
                continue;
            }
            if (j == targetIndex || target < nums[i] + nums[j])
            {
                j--;
                continue;
            }
            tempSet.insert({nums[targetIndex], nums[i], nums[j]});
            i++;
            j--;
        }
    }
    vector<vector<int>> result = vector(tempSet.begin(), tempSet.end());
    return result;
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