#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
private:
    unordered_map<char, char> converter = {
        {'0', '1'},
        {'1', '0'}};

    string invert(string res)
    {
        for (char &c : res)
        {
            c = converter[c];
        }
        return res;
    }

    string getResult(int n)
    {
        if (n == 1)
        {
            return "0";
        }
        string prev = getResult(n - 1);
        string invertString = invert(prev);
        reverse(invertString.begin(), invertString.end());
        return prev + '1' + invertString;
    }

public:
    char findKthBit(int n, int k)
    {
        string result = getResult(n);
        return result[k - 1];
    }
};

int main()
{
    Solution sln;
    cout << sln.findKthBit(3, 1) << endl;
    cout << sln.findKthBit(4, 11) << endl;
    return 0;
}