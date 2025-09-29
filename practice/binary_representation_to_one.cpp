#include <iostream>
#include <string>

using namespace std;

int num_steps(string s)
{
    int n = 0;
    while (s != "1")
    {
        // cout << s.back() << endl;
        if (s.back() == '0')
        {
            s.pop_back();
        }
        else
        {
            int i = s.length() - 1;
            while (s[i] != '0' && i >= 0)
            {
                if (s[i] == '1')
                    s[i] = '0';
                i--;
            }
            if (i != -1)
            {
                s[i] = '1';
            }
            else
            {
                s = "1" + s;
            }
        }
        n++;
    }
    return n;
}

int main()
{
    num_steps("1101");
    return 0;
}