#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = 0;
        for (int i = 1; i < n; i++)
        {
            result += 1;
            while (result & x)
            {
                result = result << 1;
            }
        }
        return result | x;
    }
};

int main()
{
    Solution sln;
    int n, x;
    cout << sln.minEnd(n = 2, x = 5) << endl;
    cout << sln.minEnd(n = 3, x = 5) << endl;
    cout << sln.minEnd(n = 3, x = 4) << endl;
    cout << sln.minEnd(n = 4, x = 4) << endl;
    return 0;
}