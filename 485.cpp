#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxCount = 0;
        for (int &num : nums)
        {
            count += num;
            if (num == 0)
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        return max(maxCount, count);
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.findMaxConsecutiveOnes(nums = {1, 1, 0, 1, 1, 1}) << endl;
    cout << sln.findMaxConsecutiveOnes(nums = {1, 0, 1, 1, 0, 1}) << endl;
    return 0;
}