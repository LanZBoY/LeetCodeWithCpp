#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> repeatCount;
        for (char &c : s)
            repeatCount[c]++;
        auto cmp = [](pair<char, int> &a, pair<char, int> &b)
        {
            return b.first > a.first;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (pair<char, int> p : repeatCount)
        {
            pq.push(p);
        }
        string res = "";
        while (!pq.empty())
        {
            pair<char, int> cur = pq.top();
            pq.pop();
            int cur_repeat_t = repeatLimit;
            while (cur.second && cur_repeat_t--)
            {
                res.push_back(cur.first);
                cur.second--;
                if (cur.second && cur_repeat_t == 0 && !pq.empty())
                {
                    pair<char, int> tmp = pq.top();
                    pq.pop();
                    tmp.second--;
                    res.push_back(tmp.first);
                    if (tmp.second > 0)
                        pq.push(tmp);
                    cur_repeat_t = repeatLimit;
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution sln;
    cout << sln.repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy", 2) << endl;
    cout << sln.repeatLimitedString("aababab", 2) << endl;
    cout << sln.repeatLimitedString("cczazcc", 3) << endl;
    return 0;
}