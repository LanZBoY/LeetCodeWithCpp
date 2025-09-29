#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    int i = 0;
    int j = 0;
    string result = "";
    while (i < word1.length() && j < word2.length())
    {
        result.push_back(word1[i++]);
        result.push_back(word2[j++]);
    }
    while (i < word1.length())
    {
        result.push_back(word1[i++]);
    }

    while (j < word2.length())
    {
        result.push_back(word2[j++]);
    }

    return result;
}

int main()
{
    cout << mergeAlternately("abc", "pqr") << endl;
    return 0;
}