#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

using Char2Index = pair<char, int>;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr = to_string(num);
        auto cmp = [](Char2Index &a, Char2Index &b)
        {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        };
        priority_queue<Char2Index, vector<Char2Index>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < numStr.size(); i++)
        {
            pq.push({numStr[i], i});
        }
        for (int i = 0; i < numStr.size(); i++)
        {
            while (!pq.empty() && pq.top().second <= i)
            {
                pq.pop();
            }
            if (!pq.empty() && pq.top().first > numStr[i])
            {
                swap(numStr[i], numStr[pq.top().second]);
                break;
            }
            if (pq.empty())
            {
                break;
            }
        }
        return stoi(numStr);
    }
};

int main()
{
    Solution sln;
    vector<int> data = {
        98368, 2736, 9973, 22341345, 1234567, 3, 1993, 6687, 98368, 56867898, 98004365};
    for (int &num : data)
    {
        cout << sln.maximumSwap(num) << endl;
    }
    // cout << sln.maximumSwap(1993) << endl;
    return 0;
}