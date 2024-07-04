#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int maxVowels(string s, int k)
{
    int curr = 0;
    unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < k; i++)
    {
        curr += vowelSet.find(s[i]) != vowelSet.end() ? true : false;
    }
    int maxCount = curr;
    for (int i = 0, j = k; j < s.size(); i++, j++)
    {

        curr -= vowelSet.find(s[i]) != vowelSet.end() ? true : false;
        curr += vowelSet.find(s[j]) != vowelSet.end() ? true : false;
        maxCount = max(maxCount, curr);
    }
    return maxCount;
}

int main()
{
    cout << maxVowels("abciiidef", 3) << endl;
    cout << maxVowels("aeiou", 2) << endl;
    cout << maxVowels("leetcode", 3) << endl;
    cout << maxVowels("zpuerktejfp", 3) << endl;

    return 0;
}