#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        // non-overlap before merge
        while (i < n && intervals[i][1] <= newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> results;
    vector<vector<int>> intervals;
    vector<int> newInterval;

    results = sln.insert(intervals = {{1, 3}, {6, 9}}, newInterval = {2, 5});

    results = sln.insert(intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, newInterval = {4, 8});

    return 0;
}