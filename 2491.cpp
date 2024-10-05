#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        size_t h_size = skill.size() / 2;
        int compare_sum = skill[0] + skill[skill.size() - 1];
        long long res = 0;
        for (size_t i = 0; i < h_size; i++)
        {
            if (compare_sum != skill[i] + skill[skill.size() - i - 1])
            {
                return -1;
            }
            res = res + (skill[i] * skill[skill.size() - i - 1]);
        }
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> skill;

    cout << sln.dividePlayers(skill = {3, 2, 5, 1, 3, 4}) << endl;
    cout << sln.dividePlayers(skill = {3, 4}) << endl;
    cout << sln.dividePlayers(skill = {1, 1, 2, 3}) << endl;

    return 0;
}