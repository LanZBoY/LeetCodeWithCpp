#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> str_token(string target)
    {
        stringstream ss(target);
        vector<string> res;
        string token;
        while (getline(ss, token, ' '))
        {
            res.push_back(token);
        }
        return res;
    }

    bool isPrefix(vector<string> &t_1, vector<string> &t_2)
    {
        for (int i = 0, j = 0; i < t_1.size() && j < t_2.size(); ++i)
        {
            if (t_1[i] == t_2[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isSuffix(vector<string> &t_1, vector<string> &t_2)
    {
        for (int i = t_1.size() - 1, j = t_2.size() - 1; i >= 0 && j >= 0; --i)
        {
            if (t_1[i] == t_2[j])
            {
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isInsert(vector<string> &t_1, vector<string> &t_2)
    {
        int i_1 = 0;
        int j_1 = t_1.size() - 1;

        int i_2 = 0;
        int j_2 = t_2.size() - 1;
        while (i_1 <= j_1 && i_2 <= j_2)
        {
            bool changeFlag = false;
            if (t_1[i_1] == t_2[i_2])
            {
                i_1++;
                i_2++;
                changeFlag = true;
            }
            if (t_1[j_1] == t_2[j_2])
            {
                j_1--;
                j_2--;
                changeFlag = true;
            }
            if (!changeFlag)
            {
                break;
            }
        }
        return i_2 > j_2 && i_1 <= j_1;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1 == sentence2)
            return true;
        if (sentence1.size() < sentence2.size())
        {
            string tmp = sentence1;
            sentence1 = sentence2;
            sentence2 = tmp;
        }
        vector<string> t_1 = str_token(sentence1);
        vector<string> t_2 = str_token(sentence2);
        return isPrefix(t_1, t_2) || isSuffix(t_1, t_2) || isInsert(t_1, t_2);
    }
};

int main()
{
    Solution sln;

    // cout << sln.areSentencesSimilar("Eating right now", "Eating") << endl;
    // cout << sln.areSentencesSimilar("Eating right now", "now") << endl;
    cout << sln.areSentencesSimilar("My name is Haley", "My Haley") << endl;
    cout << sln.areSentencesSimilar("of", "A lot of words") << endl;
    cout << sln.areSentencesSimilar("c h p Ny", "c BDQ r h p Ny") << endl;
    return 0;
}