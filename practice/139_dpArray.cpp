#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i > -1; --i)
        {
            for (string &word : wordDict)
            {
                if (i + word.size() <= s.size() && word == s.substr(i, word.size()))
                {
                    dp[i] = dp[i + word.size()];
                }
                if (dp[i])
                {
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    string s;
    vector<string> wordDict;
    Solution sln;

    cout << sln.wordBreak(s = "leetcode", wordDict = {"leet", "code"}) << endl;
    cout << sln.wordBreak(s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"}) << endl;
    cout << sln.wordBreak(s = "catssanddog", wordDict = {"cats", "dog", "sand", "and", "cat"}) << endl;
    cout << sln.wordBreak(s = "applepenapple", wordDict = {"apple", "pen"}) << endl;
    cout << sln.wordBreak(s = "ccbb", wordDict = {"bc", "cb"}) << endl;
    cout << sln.wordBreak(s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}) << endl;
    return 0;
}