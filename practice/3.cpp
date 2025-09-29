#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int i = 0;
    int j = 0;
    unordered_set<char> charSet;
    int maxLen = 0;
    while (i < s.size())
    {
        if (j >= s.size() || charSet.find(s[j]) != charSet.end())
        {
            maxLen = max(maxLen, j - i);
            charSet.erase(s[i++]);
            continue;
        }
        charSet.insert(s[j]);
        j++;
    }
    return maxLen;
}

int main()
{
    cout << lengthOfLongestSubstring("dvdf") << endl;
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}