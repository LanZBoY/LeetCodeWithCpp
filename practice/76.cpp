#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAll(unordered_map<char, int> &tmap)
{
    for (pair<char, int> p : tmap)
    {
        if (p.second > 0)
            return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";
    unordered_map<char, int> tmap;
    pair<int, int> minPair = {0, 0};
    for (char &c : t)
    {
        tmap[c]++;
    }
    int m = s.size();
    int i = 0;
    int j = 0;
    int minSize = INT_MAX;
    while (j < m)
    {
        if (tmap.find(s[i]) != tmap.end() && !isAll(tmap))
        {
            if (tmap.find(s[j]) != tmap.end())
                tmap[s[j]]--;
            j++;
        }
        else
        {
            if (tmap.find(s[i]) != tmap.end())
                tmap[s[i]]++;
            i++;
            if (i > j)
            {
                j = i;
            }
        }
        if (isAll(tmap) && (j - i) < minSize)
        {
            minSize = j - i;
            minPair = {i, j};
        }
    }

    while (isAll(tmap))
    {
        if (j - i < minSize)
        {
            minSize = j - i;
            minPair = {i, j};
        }
        if (tmap.find(s[i]) != tmap.end())
            tmap[s[i]]++;
        i++;
    }

    return s.substr(minPair.first, minPair.second - minPair.first);
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