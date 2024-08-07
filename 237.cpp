#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> extSet;
    for (int num : nums)
    {
        if (extSet.find(num) != extSet.end())
            return true;
        extSet.insert(num);
    }
    return false;
}

int main()
{
    vector<int> nums;

    nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums) << endl;

    nums = {1, 2, 3, 4};
    cout << containsDuplicate(nums) << endl;

    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << containsDuplicate(nums) << endl;

    return 0;
}