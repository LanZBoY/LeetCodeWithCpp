#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.size(); ++i)
        {
            int oneDigit = s[i - 1] - '0';
            int twoDigit = stoi(s.substr(i - 2, 2));

            if (oneDigit != 0)
            {
                dp[i] += dp[i - 1];
            }
            if (10 <= twoDigit && 26 >= twoDigit)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution sln;
    cout << sln.numDecodings("111111111111111111111111111111111111111111111") << endl;
    cout << sln.numDecodings("12") << endl;
    cout << sln.numDecodings("226") << endl;
    cout << sln.numDecodings("123") << endl;
    cout << sln.numDecodings("7175") << endl;
    return 0;
}