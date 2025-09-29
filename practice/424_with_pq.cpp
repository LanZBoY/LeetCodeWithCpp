#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int characterReplacement(string s, int k)
{
    const int N = s.size();
    unordered_map<char, int> charCount;
    for (char &c : s)
        charCount[c]++;
    auto comp = [](pair<char, int> &a, pair<char, int> &b)
    {
        return a.second < b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)>
        pq(comp);

    for (pair<char, int> p : charCount)
        pq.push(p);

    int maxLen = 0;
    while (!pq.empty())
    {
        if (pq.top().second + k <= maxLen)
        {
            return maxLen;
        }
        char c = pq.top().first;
        int i = 0;
        int j = 0;
        int replaceK = k;
        while (j < N)
        {
            if (replaceK >= 0)
            {
                if (c != s[j++])
                {
                    replaceK--;
                }
            }
            else
            {
                if (c != s[i++])
                {
                    replaceK++;
                }
            }
            if (replaceK >= 0)
                maxLen = max(maxLen, j - i);
        }
        pq.pop();
    }
    return maxLen;
}

int main()
{
    cout << characterReplacement("AABABBA", 1) << endl;
    cout << characterReplacement("ABAB", 2) << endl;
    cout << characterReplacement("ABABAA", 2) << endl;
    cout << characterReplacement("ABBB", 2) << endl;
    return 0;
}