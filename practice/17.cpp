#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, vector<char>> keyMap = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};

void letterCombinations(string digits, string current, vector<string> &result)
{
    if (digits.empty())
    {
        if (!current.empty())
        {
            result.push_back(current);
        }
        return;
    }
    for (char c : keyMap[digits[0]])
    {
        current.push_back(c);
        letterCombinations(digits.substr(1, digits.size()), current, result);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> result;
    letterCombinations(digits, "", result);
    return result;
}

int main()
{
    vector<string> result;
    result = letterCombinations("23");
    result = letterCombinations("");
    result = letterCombinations("2");

    return 0;
}