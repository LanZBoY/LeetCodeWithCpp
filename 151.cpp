#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWords(string s)
{
    const char WHITE_SPACE = ' ';
    int i = 0;
    int s_index = 0;
    stack<string> temp;
    while (i < s.size())
    {
        if (s[i] == WHITE_SPACE)
        {
            temp.push(s.substr(s_index, i - s_index));
            s_index = i + 1;
        }
        i++;
    }
    temp.push(s.substr(s_index, i - s_index));
    string result = "";
    while (!temp.empty())
    {
        if (temp.top() == "")
        {
            temp.pop();
            continue;
        }

        result += temp.top() + " ";
        temp.pop();
    }
    result.pop_back();
    return result;
}

int main()
{
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("  hello world  ") << endl;
    return 0;
}