#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[dp.size() - 1], dp[dp.size() - 2]);
}

int main()
{
    vector<int> costs;

    costs = {10, 15, 20};
    cout << minCostClimbingStairs(costs) << endl;

    costs = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(costs) << endl;

    return 0;
}