#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> counter;
    for (char c : magazine)
    {
        counter[c]++;
    }
    for (char c : ransomNote)
    {
        counter[c]--;
        if (counter[c] < 0)
            return false;
    }
    return true;
}

int main()
{
    cout << canConstruct("a", "b") << endl;
    cout << canConstruct("aa", "ab") << endl;
    cout << canConstruct("aa", "aab") << endl;
    return 0;
}