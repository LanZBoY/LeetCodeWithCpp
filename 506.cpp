#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

ostream &operator<<(ostream &outs, const vector<string> &res)
{
    outs << "[";
    int i = 0;
    for (string s : res)
    {
        if (i < res.size() - 1)
        {
            outs << s << ", ";
        }
        else
        {
            outs << s;
        }
        i++;
    }
    outs << "]";
    return outs;
}

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> sorted_arr(score.begin(), score.end());
        sort(sorted_arr.begin(), sorted_arr.end(), greater<>());
        unordered_map<int, int> rk_map;
        int rk = 1;
        for (int sco : sorted_arr)
        {
            if (rk_map.find(sco) == rk_map.end())
            {
                rk_map[sco] = rk++;
            }
        }
        unordered_map<int, string> rk_to_string = {
            {1, "Gold Medal"},
            {2, "Silver Medal"},
            {3, "Bronze Medal"}};
        vector<string> res(score.size(), "");
        for (int i = 0; i < score.size(); ++i)
        {
            int tmp_rk = rk_map[score[i]];
            if (tmp_rk <= 3)
            {
                res[i] = rk_to_string[tmp_rk];
            }
            else
            {
                res[i] = to_string(tmp_rk);
            }
        }
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> score;
    vector<string> res;
    res = sln.findRelativeRanks(score = {5, 4, 3, 2, 1});
    cout << res << endl;
    res = sln.findRelativeRanks(score = {10, 3, 8, 9, 4});
    cout << res << endl;
    return 0;
}