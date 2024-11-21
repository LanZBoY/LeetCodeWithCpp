#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{

public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> flattenFactory;
        for (auto &cur : factory)
        {
            for (int i = 0; i < cur[1]; i++)
            {
                flattenFactory.push_back(cur[0]);
            }
        }
        int robotN = robot.size();
        int factoryN = flattenFactory.size();
        vector<vector<long long>> dp(robotN + 1, vector<long long>(factoryN + 1, 0));
        for (int i = 0; i < robotN; i++)
        {
            dp[i][factoryN] = 1e12;
        }
        for (int i = robotN - 1; i >= 0; i--)
        {
            for (int j = factoryN - 1; j >= 0; j--)
            {
                long long select = abs(flattenFactory[j] - robot[i]) + dp[i + 1][j + 1];
                long long non_select = dp[i][j + 1];
                dp[i][j] = min(select, non_select);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution sln;
    vector<int> robot;
    vector<vector<int>> factory;
    cout << sln.minimumTotalDistance(
                robot = {0, 4, 6},
                factory = {{2, 2}, {6, 2}})
         << endl;
    cout << sln.minimumTotalDistance(
                robot = {1, -1},
                factory = {{-2, 1}, {2, 1}})
         << endl;
    cout << sln.minimumTotalDistance(
                robot = {9, 11, 99, 101},
                factory = {{10, 1}, {7, 1}, {14, 1}, {100, 1}, {96, 1}, {103, 1}})
         << endl;
    return 0;
}