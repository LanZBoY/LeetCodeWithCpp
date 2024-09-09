#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isNeedMerge(vector<int> &a, vector<int> &b)
    {
        return b[0] <= a[1];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (isNeedMerge(res[res.size() - 1], intervals[i]))
            {
                res[res.size() - 1][0] = min(res[res.size() - 1][0], intervals[i][0]);
                res[res.size() - 1][1] = max(res[res.size() - 1][1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> results;
    vector<vector<int>> intervals;

    results = sln.merge(intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    results = sln.merge(intervals = {{1, 4}, {4, 5}});

    return 0;
}