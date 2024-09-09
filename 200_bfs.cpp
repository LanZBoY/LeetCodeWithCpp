#include <iostream>
#include <queue>

using namespace std;

const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int numIslands(vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    int M = grid.size();
    int N = grid[0].size();
    vector<vector<bool>> visited = vector(M, vector(N, false));
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '1')
            {
                visited[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    auto [ci, cj] = q.front();
                    grid[ci][cj] = '0';

                    for (auto [x, y] : dirs)
                    {
                        int nextI = ci + x;
                        int nextJ = cj + y;
                        if (nextI >= 0 && nextJ >= 0 && nextI < M && nextJ < N && !visited[nextI][nextJ] && grid[nextI][nextJ] == '1')
                        {
                            visited[nextI][nextJ] = true;
                            q.push({nextI, nextJ});
                        }
                    }
                    q.pop();
                }
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;

    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;

    grid = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}