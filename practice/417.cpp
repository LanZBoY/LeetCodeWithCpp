#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(pair<int, int> startPoint, vector<vector<int>> &heights, vector<vector<bool>> &from)
{
    if (from[startPoint.first][startPoint.second])
        return;
    from[startPoint.first][startPoint.second] = true;
    int M = heights.size();
    int N = heights[0].size();
    for (auto [dirx, diry] : dirs)
    {
        int nexti = startPoint.first + dirx;
        int nextj = startPoint.second + diry;
        if (nexti >= 0 && nexti < M && nextj >= 0 && nextj < N)
        {
            pair<int, int> nextPoint = {nexti, nextj};
            if (heights[nextPoint.first][nextPoint.second] >= heights[startPoint.first][startPoint.second])
            {
                dfs(nextPoint, heights, from);
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int M = heights.size();
    int N = heights[0].size();
    vector<vector<bool>> fromPacific = vector(M, vector(N, false));
    vector<vector<bool>> fromAtlantic = vector(M, vector(N, false));

    for (int i = 0; i < M; i++)
    {
        dfs({i, 0}, heights, fromPacific);
        dfs({i, N - 1}, heights, fromAtlantic);
    }
    for (int i = 0; i < N; i++)
    {
        dfs({0, i}, heights, fromPacific);
        dfs({M - 1, i}, heights, fromAtlantic);
    }

    vector<vector<int>> results;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (fromPacific[i][j] && fromAtlantic[i][j])
            {
                results.push_back({i, j});
            }
        }
    }
    return results;
}

int main()
{
    vector<vector<int>> heights;
    vector<vector<int>> results;
    heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    results = pacificAtlantic(heights);
    heights = {{1}};
    results = pacificAtlantic(heights);
    return 0;
}