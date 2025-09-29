#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int characterReplacement(string s, int k)
{
    unordered_set<char> checkSet(s.begin(), s.end());
    int maxLen = 0;
    int N = s.size();
    for (char c : checkSet)
    {
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