#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> needMap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (needMap.find(nums[i]) != needMap.end())
        {
            return {needMap[nums[i]], i};
        }
        needMap[target - nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums;
    int target;
    vector<int> result;

    nums = {2, 7, 11, 15};
    target = 9;
    result = twoSum(nums, target);

    nums = {3, 2, 4};
    target = 6;
    result = twoSum(nums, target);

    nums = {3, 3};
    target = 6;
    result = twoSum(nums, target);

    return 0;
}