#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string reverseVowels(string s)
{
    int i = 0;
    int j = s.size() - 1;
    unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (i < j)
    {
        if (vowelSet.find(s[i]) != vowelSet.end() && vowelSet.find(s[j]) != vowelSet.end())
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
            continue;
        }
        if (vowelSet.find(s[i]) == vowelSet.end())
        {
            i++;
            continue;
        }
        if (vowelSet.find(s[j]) == vowelSet.end())
        {
            j--;
            continue;
        }
    }
    return s;
}

int main()
{
    cout << reverseVowels("hello") << endl;
    cout << reverseVowels("leetcode") << endl;
    return 0;
}