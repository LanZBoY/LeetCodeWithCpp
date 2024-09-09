#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    int fitInverval(int c_day, vector<Interval> intervals)
    {
        if (intervals.empty())
            return c_day;
        vector<Interval> remainIntervals;
        int i = 0;
        int j = 1;
        while (j < intervals.size())
        {
            if (intervals[i].end > intervals[j].start)
            {
                remainIntervals.push_back(intervals[j]);
            }
            else
            {
                i = j;
            }
            j++;
        }
        return fitInverval(c_day + 1, remainIntervals);
    }
    int minMeetingRooms(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b)
             {
                 return a.end < b.end;
             });
        return fitInverval(0, intervals);
    }
};

int main()
{
    vector<Interval> intervals;
    Solution sln;
    cout << sln.minMeetingRooms(intervals = {Interval(0, 40), Interval(5, 10), Interval(15, 20)}) << endl;
    cout << sln.minMeetingRooms(intervals = {Interval(4, 9)}) << endl;
    return 0;
}