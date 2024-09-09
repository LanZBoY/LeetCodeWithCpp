#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void resetMaxMin(int &max, int &min)
    {
        max = 1;
        min = 1;
    }
    int maxProduct(vector<int> &nums)
    {
        int res = INT_MIN;
        for (int &num : nums)
        {
            res = max(num, res);
        }
        int curMax = 1;
        int curMin = 1;
        for (int &num : nums)
        {
            if (num == 0)
            {
                resetMaxMin(curMax, curMin);
                continue;
            }

            int tempMaxPro = curMax * num;
            int tempMinPro = curMin * num;

            curMax = max(tempMaxPro, tempMinPro);
            curMax = max(curMax, num);

            curMin = min(tempMaxPro, tempMinPro);
            curMin = min(curMin, num);

            res = max(curMax, res);
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    Solution sln;
    nums = {-2, 0, -1};
    cout << sln.maxProduct(nums) << endl;
    return 0;
}