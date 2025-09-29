#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{

public:
    char findKthBit(int n, int k)
    {
        string seq = "0";
        for (int i = 1; i < n && k > seq.size(); ++i)
        {
            seq += '1';
            string temp = seq;
            for (int j = temp.size() - 2; j >= 0; j--)
            {
                char invertBit = (temp[j] == '1') ? '0' : '1';
                seq += invertBit;
            }
        }
        return seq[k - 1];
    }
};

int main()
{
    Solution sln;
    cout << sln.findKthBit(3, 1) << endl;
    cout << sln.findKthBit(4, 11) << endl;
    return 0;
}