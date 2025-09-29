#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    const int numOfAlpha = 26;
    int count[numOfAlpha];
    for (int &num : count)
    {
        num = 0;
    }

    for (char &c : s)
    {
        count[c % 'a']++;
    }

    for (char &c : t)
    {
        int slot = c % 'a';
        count[slot]--;
        if (count[slot] < 0)
            return false;
    }

    return true;
}

int main()
{
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagram("rat", "car") << endl;
    cout << isAnagram("zaz", "caz") << endl;
    return 0;
}