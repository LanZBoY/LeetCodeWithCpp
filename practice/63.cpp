#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getDpResult(int i, int j, vector<vector<int>> &grids, vector<vector<int>> &obstacleGrid)
    {
        if (i == 0 && j == 0)
            return obstacleGrid[i][j] ? 0 : 1;
        int up = i >= 1 ? grids[i - 1][j] : 0;
        int left = j >= 1 ? grids[i][j - 1] : 0;
        return obstacleGrid[i][j] ? 0 : up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> grids(m, vector(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grids[i][j] = getDpResult(i, j, grids, obstacleGrid);
            }
        }
        return grids[m - 1][n - 1];
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> obstacleGrid;
    cout << sln.uniquePathsWithObstacles(obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << endl;
    cout << sln.uniquePathsWithObstacles(obstacleGrid = {{0, 1}, {0, 0}}) << endl;
    return 0;
}