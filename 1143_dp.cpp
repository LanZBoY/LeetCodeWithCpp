#include <iostream>
#include <vector>

using namespace std;

// LCS("abcde", "ace");
// 1 + LCS("abcd", "ac");
// 1 + max(LCS("abc", "ac"), LCS("abcd", "a"));
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp;
    int m = text1.size();
    int n = text2.size();
    for (int i = 0; i < m; i++)
    {
        dp.push_back(vector(n, 0));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int upNum = i == 0 ? 0 : dp[i - 1][j];
            int leftNum = j == 0 ? 0 : dp[i][j - 1];
            int leftupNum = i != 0 && j != 0 ? dp[i - 1][j - 1] : 0;
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + leftupNum;
            }
            else
            {
                dp[i][j] = max(upNum, leftNum);
            }
        }
    }
    return dp[m - 1][n - 1];
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