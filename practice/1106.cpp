#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
private:
    pair<int, int> getSubRange(int start, string &expression)
    {
        stack<char> openClose;
        openClose.push(expression[start]);
        int i = start + 1;
        while (!openClose.empty())
        {
            switch (expression[i])
            {
            case '(':
                openClose.push(expression[i]);
                break;
            case ')':
                openClose.pop();
                break;
            default:
                break;
            }
            i++;
        }
        return {start, i - 1};
    }

    char parse_and(pair<int, int> range, string &expression)
    {
        char res = 0;

        for (int i = range.first; i < range.second; ++i)
        {
            switch (expression[i])
            {
            case '!':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_not(subRange, expression);
                i = subRange.second;
                break;
            }
            case '&':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_and(subRange, expression);
                i = subRange.second;
                break;
            }
            case '|':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_or(subRange, expression);
                i = subRange.second;
                break;
            }
            case 't':
            case 'f':
            {
                res = expression[i];
                break;
            }
            default:
                break;
            }
            if (res == 'f')
                break;
        }

        return res;
    }

    char parse_or(pair<int, int> range, string &expression)
    {
        char res = 0;

        for (int i = range.first; i < range.second; ++i)
        {
            switch (expression[i])
            {
            case '!':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_not(subRange, expression);
                i = subRange.second;
                break;
            }
            case '&':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_and(subRange, expression);
                i = subRange.second;
                break;
            }
            case '|':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_or(subRange, expression);
                i = subRange.second;
                break;
            }
            case 't':
            case 'f':
            {
                res = expression[i];
                break;
            }
            default:
                break;
            }
            if (res == 't')
                break;
        }

        return res;
    }

    char parse_not(pair<int, int> range, string &expression)
    {
        char res = 0;

        for (int i = range.first; i < range.second; ++i)
        {
            switch (expression[i])
            {
            case '!':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_not(subRange, expression);
                i = subRange.second;
                break;
            }
            case '&':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_and(subRange, expression);
                i = subRange.second;
                break;
            }
            case '|':
            {
                pair<int, int> subRange = getSubRange(i + 1, expression);
                res = parse_or(subRange, expression);
                i = subRange.second;
                break;
            }
            case 't':
            case 'f':
            {
                res = expression[i];
                break;
            }
            default:
                break;
            }
        }
        return res == 't' ? 'f' : 't';
    }
    char parse(string &expression)
    {
        char res;
        switch (expression[0])
        {
        case '!':
            res = parse_not({1, expression.size() - 1}, expression);
            break;
        case '&':
            res = parse_and({1, expression.size() - 1}, expression);
            break;
        case '|':
            res = parse_or({1, expression.size() - 1}, expression);
            break;
        default:
            break;
        }
        return res;
    }

public:
    bool parseBoolExpr(string expression)
    {
        char res = parse(expression);
        return res == 't' ? true : false;
    }
};

int main()
{
    Solution sln;
    cout << sln.parseBoolExpr("|(&(t,f,t),t)") << endl;

    return 0;
}