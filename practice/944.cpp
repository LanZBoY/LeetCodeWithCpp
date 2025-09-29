#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<pair<int, int>, int>> rottenQueue;
    int m = grid.size(), n = grid[0].size();
    // init for the first day; 2 for rotten, 1 for fresh, 0 is empty cell.
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 2)
                rottenQueue.push({{i, j}, 0});

    int c_minute;
    while (!rottenQueue.empty())
    {
        pair<int, int> c_Rotten = rottenQueue.front().first;
        c_minute = rottenQueue.front().second;

        if (c_Rotten.first + 1 < m && grid[c_Rotten.first + 1][c_Rotten.second] == 1)
        {
            grid[c_Rotten.first + 1][c_Rotten.second]++;
            rottenQueue.push({{c_Rotten.first + 1, c_Rotten.second}, c_minute + 1});
        }
        if (c_Rotten.first - 1 >= 0 && grid[c_Rotten.first - 1][c_Rotten.second] == 1)
        {
            grid[c_Rotten.first - 1][c_Rotten.second]++;
            rottenQueue.push({{c_Rotten.first - 1, c_Rotten.second}, c_minute + 1});
        }
        if (c_Rotten.second + 1 < n && grid[c_Rotten.first][c_Rotten.second + 1] == 1)
        {
            grid[c_Rotten.first][c_Rotten.second + 1]++;
            rottenQueue.push({{c_Rotten.first, c_Rotten.second + 1}, c_minute + 1});
        }
        if (c_Rotten.second - 1 >= 0 && grid[c_Rotten.first][c_Rotten.second - 1] == 1)
        {
            grid[c_Rotten.first][c_Rotten.second - 1]++;
            rottenQueue.push({{c_Rotten.first, c_Rotten.second - 1}, c_minute + 1});
        }

        rottenQueue.pop();
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                return -1;

    return c_minute;
}

int main()
{
    vector<vector<int>> grid;

    grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid) << endl;
    grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(grid) << endl;
    grid = {{0, 2}};
    cout << orangesRotting(grid) << endl;
    return 0;
}