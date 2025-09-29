#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            {
                i++;
                continue;
            }
            if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
            {
                j--;
                continue;
            }
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(" ") << endl;
    cout << s.isPalindrome("0P") << endl;
    return 0;
}