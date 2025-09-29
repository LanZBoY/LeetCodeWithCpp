#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        size_t t = 0;
        while ((t = s.find("AB")) != string::npos || (t = s.find("CD")) != string::npos)
        {
            s.erase(t, 2);
        }
        return s.size();
    }
};

int main()
{
    Solution sln;
    cout << sln.minLength("ABFCACDB") << endl;
    cout << sln.minLength("ACBBD") << endl;
    return 0;
}