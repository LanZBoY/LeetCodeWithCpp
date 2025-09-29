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
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b)
             {
                 return a.end < b.end;
             });
        int i = 0;
        int j = 1;
        while (j < intervals.size())
        {
            if (intervals[i].end > intervals[j].start)
            {
                return false;
            }
            else
            {
                i = j;
            }
            j++;
        }
        return true;
    }
};

int main()
{
    vector<Interval> intervals;
    Solution sln;
    sln.canAttendMeetings(intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)});
    sln.canAttendMeetings(intervals = {Interval(5, 8), Interval(9, 15)});
    return 0;
}