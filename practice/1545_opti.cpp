#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';
        int len = 1 << n; // len of bits

        if (k == len / 2)
        {
            return '1';
        }
        if (k > len / 2)
        {
            char invertBit = findKthBit(n - 1, len - k);
            return invertBit == '0' ? '1' : '0';
        }
        return findKthBit(n - 1, k);
    }
};

int main()
{
    Solution sln;
    cout << sln.findKthBit(3, 1) << endl;
    cout << sln.findKthBit(4, 11) << endl;
    return 0;
}