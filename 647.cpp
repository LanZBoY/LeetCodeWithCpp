#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void checkPair(int l, int r, string &s, int &count)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            checkPair(i, i, s, count);
            checkPair(i, i + 1, s, count);
        }
        return count;
    }
};

int main()
{
    Solution *sln;
    sln = new Solution();
    cout << sln->countSubstrings("aaa") << endl;
    cout << sln->countSubstrings("abc") << endl;
    cout << sln->countSubstrings("cbbd") << endl;
    cout << sln->countSubstrings("babad") << endl;

    return 0;
}