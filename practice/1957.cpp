#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string res;
        res.reserve(s.size());
        char prev = 0;
        int counter = 0;
        for (char &c : s)
        {
            if (prev != c)
            {
                counter = 0;
            }
            else
            {
                counter++;
            }

            if (counter < 2)
                res.push_back(c);
            prev = c;
        }
        return res;
    }
};

int main()
{
    Solution sln;
    cout << sln.makeFancyString("leeetcode") << endl;
    cout << sln.makeFancyString("aaabaaaa") << endl;
    cout << sln.makeFancyString("aab") << endl;
    return 0;
}