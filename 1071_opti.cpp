#include <iostream>
#include <string>
#include <numeric>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
    {
        return "";
    }
    int gcd_num = gcd(str1.size(), str2.size());
    return str1.substr(0, gcd_num);
}

int main()
{
    cout << gcdOfStrings("ABCABC", "ABC") << endl;
    cout << gcdOfStrings("LEET", "CODE") << endl;
    return 0;
}