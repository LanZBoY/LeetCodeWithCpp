#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(vector<string> &strs)
{
    if (strs.empty())
    {
        return "[]";
    }
    string result;
    for (int i = 0; i < strs.size() - 1; i++)
    {
        result += "\"" + strs[i] + "\"" + ", ";
    }
    result += "\"" + strs[strs.size() - 1] + "\"";
    return "[" + result + "]";
}

vector<string> decode(string s)
{
    string tmp;
    bool startPush = false;
    vector<string> res;
    for (char &c : s)
    {
        if (c == '\"')
        {
            if (startPush)
            {
                res.push_back(tmp);
            }
            startPush = !startPush;
            tmp.clear();
            continue;
        }
        tmp.push_back(c);
    }
    return res;
}

int main()
{
    vector<string> strs;
    string singleString;
    strs = {"neet", "code", "love", "you"};
    singleString = encode(strs);
    cout << singleString << endl;
    strs = decode(singleString);
}