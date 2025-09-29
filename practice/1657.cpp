#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
        return false;
    unordered_map<char, int> wordCount_1;
    unordered_map<char, int> wordCount_2;
    for (char c : word1)
        wordCount_1[c]++;
    for (char c : word2)
        wordCount_2[c]++;
    vector<int> temp_1;
    vector<int> temp_2;
    for (auto pair : wordCount_1)
    {
        temp_1.push_back(pair.second);
        if (wordCount_2.find(pair.first) == wordCount_2.end())
            return false;
        temp_2.push_back(wordCount_2[pair.first]);
    }
    sort(temp_1.begin(), temp_1.end());
    sort(temp_2.begin(), temp_2.end());
    for (int i = 0; i < temp_1.size(); i++)
    {
        if (temp_1[i] != temp_2[i])
            return false;
    }
    return true;
}

int main()
{
    cout << closeStrings("abcde", "aecdb") << endl;
    cout << closeStrings("aacabb", "bbcbaa") << endl;
    cout << closeStrings("abc", "bca") << endl;
    cout << closeStrings("aa", "a") << endl;
    cout << closeStrings("cabbba", "abbccc") << endl;
    return 0;
}