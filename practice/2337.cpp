#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        if (start.size() != target.size())
            return false;
        int n = start.size();
        vector<pair<char, int>> s_order;
        vector<pair<char, int>> e_order;

        for (int i = 0; i < n; i++)
        {
            if (start[i] != '_')
            {
                s_order.emplace_back(start[i], i);
            }
            if (target[i] != '_')
            {
                e_order.emplace_back(target[i], i);
            }
        }

        if (s_order.size() != e_order.size())
            return false;

        int m = s_order.size();

        for (int i = 0; i < m; i++)
        {
            if (s_order[i].first != e_order[i].first)
                return false;
            if (s_order[i].first == 'L')
            {
                if (s_order[i].second - e_order[i].second < 0)
                    return false;
            }
            if (s_order[i].first == 'R')
            {
                if (s_order[i].second - e_order[i].second > 0)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    cout << sln.canChange("_L__R__R_", "L______RR") << endl;
    cout << sln.canChange("R_L_", "__LR") << endl;
    cout << sln.canChange("_R", "R_") << endl;
    return 0;
}