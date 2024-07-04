#include <iostream>
#include <string>

using namespace std;

string removeStars(string s)
{
    string result = "";
    for (char c : s)
    {
        if (c == '*')
        {
            result.pop_back();
            continue;
        }
        result.push_back(c);
    }
    return result;
}

int main()
{
    cout << removeStars("leet**cod*e") << endl;
    cout << removeStars("erase*****") << endl;
    return 0;
}