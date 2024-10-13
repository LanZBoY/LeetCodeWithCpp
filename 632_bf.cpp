#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();

        vector<int> indices(k, 0);

        vector<int> range = {0, INT_MAX};

        while (true)
        {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;
            for (int i = 0; i < k; ++i)
            {
                int currentEle = nums[i][indices[i]];
                if (currentEle < curMin)
                {
                    curMin = currentEle;
                    minListIndex = i;
                }

                if (currentEle > curMax)
                {
                    curMax = currentEle;
                }
            }

            if (curMax - curMin < range[1] - range[0])
            {
                range[1] = curMax;
                range[0] = curMin;
            }

            if (++indices[minListIndex] == nums[minListIndex].size())
                break;
        }
        return range;
    }
};

int main()
{
    Solution sln;
    vector<int> minRange;
    vector<vector<int>> nums;
    minRange = sln.smallestRange(nums = {{4, 10, 15, 24, 26},
                                         {0, 9, 12, 20},
                                         {5, 18, 22, 30}});
    minRange = sln.smallestRange(nums = {{1, 2, 3},
                                         {1, 2, 3},
                                         {1, 2, 3}});
    return 0;
}