#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void swap(char &a, char &b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }

public:
    int minSwaps(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        int offset = 0;
        int res = 0;
        while (i < j)
        {
            if (s[i] == '[')
            {
                offset++;
            }
            else
            {
                offset--;
            }
            if (offset < 0)
            {
                while (j >= 0 && s[j] != '[')
                {
                    j--;
                }
                swap(s[i], s[j]);
                res++;
                offset++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sln;

    cout << sln.minSwaps("][][") << endl;
    cout << sln.minSwaps("]]][[[") << endl;
    cout << sln.minSwaps("[]") << endl;
    return 0;
}