#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int maxVowels(string s, int k)
{
    unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    int maxCount = 0;
    string slidingWindow = "";
    for (char c : s)
    {
        if (slidingWindow.size() == k)
        {
            if (vowelSet.find(slidingWindow[0]) != vowelSet.end())
            {
                count--;
            }
            slidingWindow.erase(0, 1);
        }
        if (vowelSet.find(c) != vowelSet.end())
        {
            count++;
        }
        slidingWindow.push_back(c);
        if (maxCount < count)
            maxCount = count;
        if (maxCount == k)
            return k;
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