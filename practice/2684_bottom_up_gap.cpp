#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); ++i)
        {
            dp[i][0] = 1;
        }
        int maxStep = 1;
        for (int j = 1; j < grid[0].size(); ++j)
        {
            bool gap = true;
            for (int i = 0; i < grid.size(); ++i)
            {
                int result = 0;
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] && dp[i - 1][j - 1] > 0)
                    result = max(result, dp[i - 1][j - 1] + 1);
                if (j - 1 >= 0 && grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0)
                    result = max(result, dp[i][j - 1] + 1);
                if (i + 1 < grid.size() && j - 1 >= 0 && grid[i][j] > grid[i + 1][j - 1] && dp[i + 1][j - 1] > 0)
                    result = max(result, dp[i + 1][j - 1] + 1);
                if (result != 0)
                {
                    gap = false;
                }
                dp[i][j] = result;
                maxStep = max(dp[i][j], maxStep);
            }
            if (gap)
                return maxStep - 1;
        }
        return maxStep - 1;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> grids;
    cout << sln.maxMoves(grids = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}}) << endl;
    cout << sln.maxMoves(grids = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}}) << endl;
    return 0;
}