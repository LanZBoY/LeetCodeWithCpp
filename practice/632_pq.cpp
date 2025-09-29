#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    struct RangeInfo
    {
        int val;
        size_t IList;
        size_t IofList;
    };

    struct cmp
    {
        bool operator()(RangeInfo &a, RangeInfo &b)
        {
            return a.val > b.val;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<RangeInfo, vector<RangeInfo>, cmp> pq;
        vector<int> range = {0, INT_MAX};
        int currMax = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++)
        {
            RangeInfo c = {nums[i][0], i, 0};
            if (c.val > currMax)
            {
                currMax = c.val;
            }
            pq.push(c);
        }
        if (currMax - pq.top().val < range[1] - range[0])
        {
            range[1] = currMax;
            range[0] = pq.top().val;
        }

        while (!pq.empty() && pq.top().IofList + 1 < nums[pq.top().IList].size())
        {
            RangeInfo current = pq.top();
            RangeInfo next = {nums[current.IList][current.IofList + 1],
                              current.IList,
                              current.IofList + 1};
            if (next.val > currMax)
                currMax = next.val;
            pq.pop();
            pq.push(next);
            if (currMax - pq.top().val < range[1] - range[0])
            {
                range[1] = currMax;
                range[0] = pq.top().val;
            }
        }
        return range;
    }
};

int main()
{
    Solution sln;
    vector<int> minRange;
    vector<vector<int>> nums;
    // minRange = sln.smallestRange(nums = {{4, 10, 15, 24, 26},
    //                                      {0, 9, 12, 20},
    //                                      {5, 18, 22, 30}});
    // minRange = sln.smallestRange(nums = {{1, 2, 3},
    //                                      {1, 2, 3},
    //                                      {1, 2, 3}});
    minRange = sln.smallestRange(nums = {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}, {-8, 8}, {-9, 9}, {-10, 10}, {-11, 11}, {-12, 12}, {-13, 13}, {-14, 14}, {-15, 15}, {-16, 16}, {-17, 17}, {-18, 18}, {-19, 19}, {-20, 20}, {-21, 21}, {-22, 22}, {-23, 23}, {-24, 24}, {-25, 25}, {-26, 26}, {-27, 27}, {-28, 28}, {-29, 29}, {-30, 30}, {-31, 31}, {-32, 32}, {-33, 33}, {-34, 34}, {-35, 35}, {-36, 36}, {-37, 37}, {-38, 38}, {-39, 39}, {-40, 40}, {-41, 41}, {-42, 42}, {-43, 43}, {-44, 44}, {-45, 45}, {-46, 46}, {-47, 47}, {-48, 48}, {-49, 49}, {-50, 50}, {-51, 51}, {-52, 52}, {-53, 53}, {-54, 54}, {-55, 55}});
    return 0;
}