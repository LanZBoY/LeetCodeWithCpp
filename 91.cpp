#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string &s, int current, int prev)
    {
        if (prev == -1)
        {
            if (current == s.size())
                return 1;
            if (s[current] == '0')
            {
                return 0;
            }
            if (s[current] <= '2')
            {
                return numDecodings(s, current + 1, -1) + numDecodings(s, current + 1, current);
            }
            return numDecodings(s, current + 1, -1);
        }
        else
        {
            if (current == s.size())
                return 0;
            if (s[prev] == '1')
            {
                return numDecodings(s, current + 1, -1);
            }
            else
            {
                if (s[current] <= '6')
                {
                    return numDecodings(s, current + 1, -1);
                }
            }
        }
        return 0;
    }
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        if (s[0] <= '2')
        {
            return numDecodings(s, 1, -1) + numDecodings(s, 1, 0);
        }
        return numDecodings(s, 1, -1);
    }
};

int main()
{
    Solution sln;
    cout << sln.numDecodings("111111111111111111111111111111111111111111111") << endl;
    return 0;
}