#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = x;
        for (int i = 1; i < n; i++)
        {
            result = (result + 1) | x;
        }
        return result;
    }
};

int main()
{
    Solution sln;
    int n, x;
    cout << sln.minEnd(n = 3, x = 4) << endl;
    cout << sln.minEnd(n = 4, x = 4) << endl;
    cout << sln.minEnd(n = 2, x = 7) << endl;
    return 0;
}