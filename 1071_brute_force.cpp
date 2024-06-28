#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countSubstring(string fullString, string targetString)
{
    if (fullString.size() == 0)
        return 0;
    int count = 0;
    for (size_t i = fullString.find(targetString); i != string::npos;
         i = fullString.find(targetString, i + targetString.length()))
    {
        ++count;
    }
    return count;
}
string gcdOfStrings(string str1, string str2)
{
    string baseString = (str1.size() > str2.size()) ? str2 : str1;
    while (!baseString.empty())
    {
        int count_1 = countSubstring(str1, baseString);
        int count_2 = countSubstring(str2, baseString);
        if (baseString.size() * count_1 == str1.size() && baseString.size() * count_2 == str2.size())
            return baseString;
        baseString.pop_back();
    }
    return baseString;
}

int main()
{
    cout << gcdOfStrings("ABCABC", "ABC") << endl;
    return 0;
}