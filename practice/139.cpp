#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool dfs(int i, string &s, vector<string> &wordDict)
    {
        if (i == s.size())
            return true;
        for (string &word : wordDict)
        {
            if (word == s.substr(i, word.size()))
            {
                if (dfs(i + word.size(), s, wordDict))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return dfs(0, s, wordDict);
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
    return 0;
}