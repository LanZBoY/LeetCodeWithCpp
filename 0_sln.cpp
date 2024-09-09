#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int i = 0;
        int j = 1;
        int count = 0;
        while (j < intervals.size())
        {
            if (intervals[i][1] > intervals[j][0]) // overlap
            {
                count++;
            }
            else
            {
                i = j;
            }
            j++;
        }
        return count;
    }
};
int main()
{
    Solution sln;
    vector<vector<int>> intervals;
    cout << sln.eraseOverlapIntervals(intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}}) << endl;
    cout << sln.eraseOverlapIntervals(intervals = {{1, 2}, {1, 2}, {1, 2}}) << endl;
    cout << sln.eraseOverlapIntervals(intervals = {{1, 2}, {2, 3}}) << endl;
    return 0;
}