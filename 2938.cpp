#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        long long res = 0;
        while (i < j)
        {
            if (s[i] == '1' && s[j] == '0')
            {
                res = res + (j - i);
                i++;
                j--;
            }
            if (s[i] == '0')
            {
                i++;
            }
            if (s[j] == '1')
            {
                j--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sln;
    cout << sln.minimumSteps("001110001110001") << endl;
    cout << sln.minimumSteps("101") << endl;
    cout << sln.minimumSteps("100") << endl;
    cout << sln.minimumSteps("0111") << endl;
    return 0;
}