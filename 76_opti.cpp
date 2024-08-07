#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";
    unordered_map<char, int> tmap;
    int n = t.size();
    int m = s.size();
    pair<int, int> minPair = {-1, -1};
    for (char &c : t)
        tmap[c]++;
    int i = 0;
    int j = 0;
    while (i < m)
    {
        if (n > 0 && j < m)
        {
            if (tmap.find(s[j]) != tmap.end())
            {
                tmap[s[j]]--;
                if (tmap[s[j]] >= 0)
                {
                    n--;
                }
            }
            j++;
        }
        else
        {
            if (tmap.find(s[i]) != tmap.end())
            {
                tmap[s[i]]++;
                if (tmap[s[i]] > 0)
                {
                    n++;
                }
            }
            i++;
        }
        if (n == 0)
        {
            if (minPair.first == -1 || j - i < minPair.second - minPair.first)
            {
                minPair = {i, j};
            }
        }
    }

    return minPair.first == -1 ? "" : s.substr(minPair.first, minPair.second - minPair.first);
}

int main()
{
    cout << minWindow("ab", "b") << endl;
    cout << minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd") << endl;
    cout << minWindow("ADOBECODEBANCNNNN", "ABC") << endl;
    cout << minWindow("cbbbacccccbbbacbabbabacbabbbabaacbaccccbcbcbcca", "abcbcabaacccababacbabcacbc") << endl;
    // acbabbabacbabbbabaacbaccccbcbc
    cout << minWindow("a", "a") << endl;
    cout << minWindow("a", "aa") << endl;
    cout << minWindow("caccaacaaaabbcaccaccc", "acccacbccc") << endl;
    cout << minWindow("babb", "baba") << endl;
    return 0;
}