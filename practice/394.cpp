#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

string decodeString(string s)
{
    string r = "";
    string numString = "";
    stack<int> numStack;
    for (char c : s)
    {
        if (isNumber(c))
        {
            numString.push_back(c);
            continue;
        }
        if (!numString.empty())
        {
            numStack.push(stoi(numString));
        }
        if (c == ']')
        {
            string placeString = "";
            while (!r.empty())
            {
                if (r.back() == '[')
                    break;
                placeString = r.back() + placeString;
                r.pop_back();
            }
            r.pop_back();
            while (numStack.top()--)
            {
                r += placeString;
            }
            numStack.pop();
            continue;
        }
        r.push_back(c);
        numString = "";
    }
    return r;
}

int main()
{
    cout << decodeString("3[a2[ac3[bc4[bc]]]]") << endl;
    return 0;
}