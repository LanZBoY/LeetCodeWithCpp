#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = 0;
        int k = nums.size();
        while (j < nums.size())
        {
            if (nums[j] == val)
            {
                k--;
                j++;
            }
            else
            {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return k;
    }
};

int main()
{
    vector<int> nums;
    int val;
    Solution sln;
    cout << sln.removeElement(nums = {3, 2, 2, 3}, val = 3) << "\n";
    cout << sln.removeElement(nums = {0, 1, 2, 2, 3, 0, 4, 2}, val = 2) << "\n";
    return 0;
}