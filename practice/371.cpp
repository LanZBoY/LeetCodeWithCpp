#include <iostream>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        int carry = (a & b) << 1;
        int res = a ^ b;
        while (carry)
        {
            a = carry;
            b = res;
            carry = (a & b) << 1;
            res = a ^ b;
        }
        return res;
    }
};

int main()
{
    Solution sln;
    cout << sln.getSum(3, 2) << endl;
    cout << sln.getSum(7, 3) << endl;
    return 0;
}
