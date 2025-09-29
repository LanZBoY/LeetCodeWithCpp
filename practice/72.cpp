#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2, unordered_map<string, int> &memo)
{
    if (memo.find(word1 + "," + word2) != memo.end())
    {
        return memo[word1 + "," + word2];
    }
    if (word1.empty() || word2.empty())
    {
        memo[word1 + "," + word2] = word1.empty() ? word2.size() : word1.size();
        return memo[word1 + "," + word2];
    }
    if (word1[0] != word2[0])
    {
        // Replace
        int minCost = 1 + minDistance(word1.substr(1, word1.size()), word2.substr(1, word2.size()), memo);
        // Delete
        minCost = min(minCost, 1 + minDistance(word1.substr(1, word1.size()), word2, memo));
        // Insert
        minCost = min(minCost, 1 + minDistance(word1, word2.substr(1, word2.size()), memo));
        memo[word1 + "," + word2] = minCost;
        return memo[word1 + "," + word2];
    }
    return minDistance(
        word1.substr(1, word1.size()),
        word2.substr(1, word2.size()), memo);
}

int minDistance(string word1, string word2)
{
    unordered_map<string, int> memo;
    return minDistance(word1, word2, memo);
}

int main()
{
    unordered_map<string, int> memo;
    cout << minDistance("horse", "ros") << endl;
    cout << minDistance("intention", "execution") << endl;
    return 0;
}