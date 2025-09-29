#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_set<int> n_set;
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (n_set.find(nums[i]) == n_set.end())
            {
                n_set.insert(nums[i]);
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.removeDuplicates(nums = {1, 1, 2}) << "\n";
    cout << sln.removeDuplicates(nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}) << "\n";

    return 0;
}