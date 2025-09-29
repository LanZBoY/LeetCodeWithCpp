#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int start, int end, string &s)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        pair<int, int> maxPair = {0, 0};
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                if (isPalindrome(i, j, s))
                {
                    if (maxPair.second - maxPair.first < j - i)
                    {
                        maxPair = {i, j};
                    }
                }
            }
        }
        return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
    }
};

int main()
{
    Solution sln;
    cout << sln.longestPalindrome("babad") << endl;
    cout << sln.longestPalindrome("cbbd") << endl;

    return 0;
}