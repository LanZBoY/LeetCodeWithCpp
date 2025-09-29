#include <iostream>
#include <vector>

using namespace std;

// LCS("abcde", "ace");
// 1 + LCS("abcd", "ac");
// 1 + max(LCS("abc", "ac"), LCS("abcd", "a"));
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector(text2.size() + 1, 0));
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 1; j < dp[i].size(); ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[text1.size()][text2.size()];
}

int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abc", "abc") << endl;
    cout << longestCommonSubsequence("abc", "def") << endl;
    cout << longestCommonSubsequence("bl", "yby") << endl;
    cout << longestCommonSubsequence("bsbininm", "jmjkbkjkv") << endl;
    return 0;
}