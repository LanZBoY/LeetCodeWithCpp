#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minObstacles(m, vector<int>(n, __INT_MAX__));

        minObstacles[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({minObstacles[0][0], 0, 0});

        while (!pq.empty())
        {
            int obstacles = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            if (row == m - 1 && col == n - 1)
            {
                return obstacles;
            }

            for (const auto &dir : dirs)
            {
                int next_row = row + dir.first;
                int next_col = col + dir.second;
                if (!(next_row >= 0 && next_col >= 0 && next_row < m && next_col < n))
                    continue;

                int next_obstacles = obstacles + grid[next_row][next_col];
                if (next_obstacles < minObstacles[next_row][next_col])
                {
                    minObstacles[next_row][next_col] = next_obstacles;
                    pq.push({next_obstacles, next_row, next_col});
                }
            }
        }
        return minObstacles[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> grid;
    Solution sln;
    cout << sln.minimumObstacles(grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}}) << endl;
    cout << sln.minimumObstacles(grid = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}}) << endl;
    return 0;
}