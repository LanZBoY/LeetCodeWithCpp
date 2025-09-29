#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> ziazags(numRows, "");
        int i = 0;
        int next_ = -1;
        for (char &c : s)
        {
            ziazags[i].push_back(c);
            if (i == 0 || i == numRows - 1)
                next_ = -next_;
            i += next_;
        }
        string res = "";
        for (string &part : ziazags)
        {
            res += part;
        }
        return res;
    }
};

int main()
{
    Solution sln;
    cout << sln.convert("PAYPALISHIRING", 3) << endl;
    cout << sln.convert("PAYPALISHIRING", 4) << endl;
    cout << sln.convert("AB", 1) << endl;
    return 0;
}