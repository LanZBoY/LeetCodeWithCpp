#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool dfs(int i, string &s, vector<string> &wordDict, unordered_map<int, bool> &memo)
    {
        if (memo.find(i) != memo.end())
        {
            return memo[i];
        }
        if (i == s.size())
        {
            return memo[i] = true;
        }
        for (string &word : wordDict)
        {
            if (word == s.substr(i, word.size()))
            {
                if (dfs(i + word.size(), s, wordDict, memo))
                {
                    return memo[i] = true;
                }
            }
        }
        return memo[i] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<int, bool> memo;
        return dfs(0, s, wordDict, memo);
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