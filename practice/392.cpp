#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0;
    int j = 0;
    while (i < t.size())
    {
        if (s[j] == t[i])
            j++;
        i++;
    }
    return j == s.size();
}

int main()
{
    cout << isSubsequence("abc", "ahbgdc") << endl;
    cout << isSubsequence("axc", "ahbgdc") << endl;
    return 0;
}