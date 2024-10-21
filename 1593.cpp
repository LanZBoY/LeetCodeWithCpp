#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    void backtracking(int start, string &s, unordered_set<string> &currentSet, int &maxLen)
    {
        maxLen = max((int)currentSet.size(), maxLen);
        for (int i = start + 1; i <= s.size(); i++)
        {
            string tmp = s.substr(start, i - start);
            if (currentSet.find(tmp) == currentSet.end())
            {
                currentSet.insert(tmp);
                backtracking(i, s, currentSet, maxLen);
                currentSet.erase(tmp);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> currentSet;
        int maxLen = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            string tmp = s.substr(0, i);
            currentSet.insert(tmp);
            backtracking(i, s, currentSet, maxLen);
            currentSet.erase(tmp);
        }
        return maxLen;
    }
};

int main()
{
    Solution sln;
    cout << sln.maxUniqueSplit("ababccc") << endl;
    cout << sln.maxUniqueSplit("aba") << endl;
    cout << sln.maxUniqueSplit("aa") << endl;
    return 0;
}