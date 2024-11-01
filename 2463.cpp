#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    long long minDistance(int robotIdx, int factoryIdx, vector<int> &robot, vector<int> &flattenFactory, vector<vector<long long>> &memo)
    {
        if (robotIdx == robot.size())
            return 0;
        if (factoryIdx == flattenFactory.size())
            return 1e12;
        if (memo[robotIdx][factoryIdx] != -1)
            return memo[robotIdx][factoryIdx];
        long long option1 = abs(robot[robotIdx] - flattenFactory[factoryIdx]) + minDistance(robotIdx + 1, factoryIdx + 1, robot, flattenFactory, memo);
        long long option2 = minDistance(robotIdx, factoryIdx + 1, robot, flattenFactory, memo);
        return memo[robotIdx][factoryIdx] = min(option1, option2);
    }

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
        vector<vector<long long>> memo(robot.size(), vector(flattenFactory.size(), -1LL));
        return minDistance(0, 0, robot, flattenFactory, memo);
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