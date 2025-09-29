#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    bool allZero(unordered_map<char, int> &in)
    {
        for (auto &tmp : in)
        {
            if (tmp.second != 0)
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        unordered_map<char, int> m_s1;
        for (char &c : s1)
        {
            m_s1[c]++;
        }

        int c_s2 = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            m_s1[s2[i]]--;
            if (i >= s1.size())
            {
                m_s1[s2[i - s1.size()]]++;
            }
            if (allZero(m_s1))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sln;
    cout << sln.checkInclusion("adc", "dcda") << endl;
    cout << sln.checkInclusion("ab", "eidbaooo") << endl;
    cout << sln.checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}