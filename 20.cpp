#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> cs;
    for (char &c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            cs.push(c);
        if (c == ')')
        {
            if (cs.empty() || cs.top() != '(')
                return false;
            cs.pop();
        }
        else if (c == '}')
        {
            if (cs.empty() || cs.top() != '{')
                return false;
            cs.pop();
        }
        else if (c == ']')
        {
            if (cs.empty() || cs.top() != '[')
                return false;
            cs.pop();
        }
    }
    return cs.empty();
}

int main()
{
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("(({}))()]") << endl;
    return 0;
}