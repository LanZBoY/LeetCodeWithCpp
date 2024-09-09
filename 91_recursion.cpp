#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodingsTD(string s, int index, vector<int> &memo)
    {
        if (index == s.size())
            return 1;
        if (s[index] == '0')
            return 0;
        if (memo[index] != -1)
            return memo[index];

        int numofWays = numDecodingsTD(s, index + 1, memo);
        if (index + 1 < s.size())
        {
            int subInt = stoi(s.substr(index, 2));
            if (subInt <= 26 && subInt > 0)
            {
                numofWays += numDecodingsTD(s, index + 2, memo);
            }
        }
        memo[index] = numofWays;
        return memo[index];
    }
    int numDecodings(string s)
    {
        vector<int> memo(s.size(), -1);
        return numDecodingsTD(s, 0, memo);
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