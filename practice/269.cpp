#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    enum NodeState
    {
        unvisited,
        visiting,
        visited,
    };

    bool ts(char currentNode, unordered_map<char, unordered_set<char>> &adjs, unordered_map<char, bool> &visited, string &result)
    {
        if (visited.find(currentNode) != visited.end())
            return visited[currentNode];
        visited[currentNode] = true;
        for (char nextNode : adjs[currentNode])
        {
            if (ts(nextNode, adjs, visited, result))
            {
                return true;
            }
        }
        visited[currentNode] = false;
        result.push_back(currentNode);
        return false;
    }

    string foreignDictionary(vector<string> &words)
    {
        unordered_map<char, unordered_set<char>> adjs;
        unordered_map<char, bool> visited;
        for (string &word : words)
        {
            for (char &c : word)
            {
                adjs[c];
            }
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            int minSize = min(words[i].size(), words[i + 1].size());
            int j = 0;
            while (j < minSize && words[i][j] == words[i + 1][j])
                j++;
            if (j < minSize)
            {
                adjs[words[i][j]].insert(words[i + 1][j]);
            }
            else if (j == minSize && words[i].size() > words[i + 1].size())
            {
                return "";
            }
        }
        string result = "";
        for (const auto &data : adjs)
        {
            if (ts(data.first, adjs, visited, result))
            {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    vector<string> words;
    Solution sln;

    // "zo"
    words = {"z", "o"};
    cout << sln.foreignDictionary(words) << endl;

    // "wertf"
    words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << sln.foreignDictionary(words) << endl;

    // ""
    words = {"wrt", "wrtfr"};
    cout << sln.foreignDictionary(words) << endl;

    // "z"
    words = {"z", "z"};
    cout << sln.foreignDictionary(words) << endl;

    // "hernf"
    words = {"hrn", "hrf", "er", "enn", "rfnn"};
    cout << sln.foreignDictionary(words) << endl;

    // ""
    words = {"wrt", "wrf", "er", "wrt"};
    cout << sln.foreignDictionary(words) << endl;

    // ""
    words = {"abcdefgh", "bdefghij", "cghij", "dfghij", "efghij", "fghij", "ghij", "hij", "ij", "j", "abcdefghi", "bdefghijk", "cghijk", "dfghijk", "efghijk", "fghijk", "ghijk", "hijk", "ijk", "jk", "k"};
    cout << sln.foreignDictionary(words) << endl;
    return 0;
}