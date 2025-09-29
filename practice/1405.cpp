#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        auto comp = [](pair<char, int> &a, pair<char, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        if (a != 0)
            pq.push({'a', a});
        if (b != 0)
            pq.push({'b', b});
        if (c != 0)
            pq.push({'c', c});
        string happyString = "";
        pair<char, int> prev = {0, 0};
        while (!pq.empty())
        {
            pair<char, int> cur = pq.top();
            pq.pop();
            for (int i = 0; i < 2 && cur.second > 0; i++)
            {
                happyString.push_back(cur.first);
                cur.second--;
                if (cur.second < prev.second)
                {
                    break;
                }
            }
            if (cur.second > 0)
            {
                if (prev.first != 0 && prev.first != cur.first)
                {
                    pq.push(prev);
                }
                prev = cur;
            }
            else
            {
                if (prev.first != 0)
                {
                    pq.push(prev);
                }
                prev = {0, 0};
            }
        }
        return happyString;
    }
};

int main(void)
{
    Solution sln;
    cout << sln.longestDiverseString(1, 1, 7) << endl;
    cout << sln.longestDiverseString(7, 1, 0) << endl;
    cout << sln.longestDiverseString(2, 8, 10) << endl;
    cout << sln.longestDiverseString(0, 8, 11) << endl;
    return 0;
}