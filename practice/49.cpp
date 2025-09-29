#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> tmp;
    for (int i = 0; i < strs.size(); i++)
    {
        string tmpstr = strs[i];
        sort(tmpstr.begin(), tmpstr.end());
        tmp[tmpstr].emplace_back(strs[i]);
    }
    vector<vector<string>> results;
    for (pair<string, vector<string>> result : tmp)
    {
        results.emplace_back(result.second);
    }
    return results;
}

int main()
{
    vector<string> strs;
    vector<vector<string>> results;

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    results = groupAnagrams(strs);

    strs = {"cab", "tin", "pew", "duh", "may", "ill", "buy", "bar", "max", "doc"};
    results = groupAnagrams(strs);

    strs = {"a"};
    results = groupAnagrams(strs);

    return 0;
}