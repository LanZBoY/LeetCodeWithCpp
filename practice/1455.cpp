#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string cur_word;
        int index = 1;
        while (ss >> cur_word)
        {
            size_t wordPos = cur_word.find(searchWord, 0);
            if (wordPos == 0)
            {
                return index;
            }
            index++;
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    cout << sln.isPrefixOfWord("i love eating burger", "burg") << endl;
    cout << sln.isPrefixOfWord("this problem is an easy problem", "pro") << endl;
    cout << sln.isPrefixOfWord("i am tired", "you") << endl;
    return 0;
}