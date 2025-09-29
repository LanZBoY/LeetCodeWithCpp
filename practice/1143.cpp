#include <iostream>
#include <vector>

using namespace std;

// LCS("abcde", "ace");
// 1 + LCS("abcd", "ac");
// 1 + max(LCS("abc", "ac"), LCS("abcd", "a"));
int longestCommonSubsequence(string text1, string text2)
{
    if (text1.empty() || text2.empty())
    {
        return 0;
    }
    if (text1[text1.size() - 1] == text2[text2.size() - 1])
    {
        return 1 + longestCommonSubsequence(text1.substr(0, text1.size() - 1), text2.substr(0, text2.size() - 1));
    }
    return max(
        longestCommonSubsequence(text1.substr(0, text1.size()), text2.substr(0, text2.size() - 1)),
        longestCommonSubsequence(text1.substr(0, text1.size() - 1), text2.substr(0, text2.size())));
}

int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abc", "abc") << endl;
    cout << longestCommonSubsequence("abc", "def") << endl;
    cout << longestCommonSubsequence("bl", "yby") << endl;
    return 0;
}