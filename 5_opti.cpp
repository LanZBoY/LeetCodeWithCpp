#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    void checkPair(int l, int r, string &s, pair<int, int> &maxPair)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxPair.second - maxPair.first + 1)
            {
                maxPair = {l, r};
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s)
    {
        pair<int, int> maxPair = {0, 0};
        for (int i = 0; i < s.size(); i++)
        {
            checkPair(i, i, s, maxPair);
            checkPair(i, i + 1, s, maxPair);
        }
        return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
    }
};

int main()
{
    Solution *sln;
    sln = new Solution();
    cout << sln->longestPalindrome("cbbd") << endl;
    sln = new Solution();
    cout << sln->longestPalindrome("babad") << endl;

    return 0;
}