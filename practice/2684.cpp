#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int step(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int result = 0;

        if (i - 1 >= 0 && j + 1 < grid[i].size() && grid[i][j] < grid[i - 1][j + 1])
            result = max(result, step(i - 1, j + 1, grid, dp));
        if (j + 1 < grid[i].size() && grid[i][j] < grid[i][j + 1])
            result = max(result, step(i, j + 1, grid, dp));
        if (i + 1 < grid.size() && j + 1 < grid[i].size() && grid[i][j] < grid[i + 1][j + 1])
            result = max(result, step(i + 1, j + 1, grid, dp));
        return dp[i][j] = 1 + result;
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector(grid[0].size(), -1));
        int maxStep = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            maxStep = max(maxStep, step(i, 0, grid, dp));
        }
        return maxStep - 1;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> grids;
    // cout << sln.maxMoves(grids = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}}) << endl;
    cout << sln.maxMoves(grids = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}}) << endl;
    return 0;
}