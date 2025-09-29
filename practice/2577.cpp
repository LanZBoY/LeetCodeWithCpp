#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid(const int &m, const int &n, const int &row, const int &col)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

public:
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // check basecase
        if (grid[0][1] - grid[0][0] > 1 && grid[1][0] - grid[0][0] > 1)
            return -1;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        while (!pq.empty())
        {
            int curStep = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];

            pq.pop();

            if (row == m - 1 && col == n - 1)
                return curStep;

            for (const auto &dir : dirs)
            {
                int next_row = row + dir.first;
                int next_col = col + dir.second;

                if (!isValid(m, n, next_row, next_col) || visited[next_row][next_col])
                    continue;

                int waitTime = (grid[next_row][next_col] - curStep) % 2 == 0 ? 1 : 0;
                int nextStep = max(grid[next_row][next_col] + waitTime, curStep + 1);
                pq.push({nextStep, next_row, next_col});
                visited[next_row][next_col] = true;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> grid;

    cout << sln.minimumTime(grid = {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}}) << endl;
    cout << sln.minimumTime(grid = {{0, 2, 4}, {3, 2, 1}, {1, 0, 4}}) << endl;
    return 0;
}