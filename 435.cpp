#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isOverlap(vector<int> &a, vector<int> &b)
{
    if (a[1] > b[0])
    {
        if (a[1] > b[1])
        {
            return 2; // case 2;
        }
        return 1; // case 1
    }
    return 0; // base case (Non-Overlap)
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int removeCount = 0;

    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int prev = 0;
    int current = 1;
    while (current < intervals.size())
    {
        int case_num = isOverlap(intervals[prev], intervals[current]);
        switch (case_num)
        {
        case 1:
            removeCount++;
            break;
        case 2:
            removeCount++;
            break;
        default:
            prev = current;
        }
        current++;
    }
    return removeCount;
}

int main()
{
    vector<vector<int>> intervals;

    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;

    intervals = {{1, 2}, {1, 2}, {1, 2}};
    cout << eraseOverlapIntervals(intervals) << endl;

    intervals = {{1, 2}, {2, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}