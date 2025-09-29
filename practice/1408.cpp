#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        for (int i = 0; i < words.size(); i++)
        {
            string searchWord = words[i];

            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[j].find(searchWord) != string::npos)
                {
                    result.push_back(searchWord);
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<string> words;
    vector<string> result;

    result = sln.stringMatching(words = {"leetcoder", "leetcode", "od", "hamlet", "am"});
    result = sln.stringMatching(words = {"mass", "as", "hero", "superhero"});
    result = sln.stringMatching(words = {"leetcode", "et", "code"});
    result = sln.stringMatching(words = {"blue", "green", "bu"});
    return 0;
}