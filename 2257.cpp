#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
private:
    bool isWalls(int i, int j, vector<vector<int>> &walls)
    {
        for (auto &wall : walls)
        {
            if (wall[0] == i && wall[1] == j)
                return true;
        }

        return false;
    }

public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        int count = 0;
        vector<vector<bool>> gridStatus(m, vector(n, true));
        for (auto &wall : walls)
        {
            gridStatus[wall[0]][wall[1]] = false;
        }
        for (auto &guard : guards)
        {
            gridStatus[guard[0]][guard[1]] = false;
            for (auto &dir : dirs)
            {
                int x = guard[0] + dir.first;
                int y = guard[1] + dir.second;
                while (x >= 0 && y >= 0 && x < m && y < n && !isWalls(x, y, walls))
                {
                    gridStatus[x][y] = false;
                    x = x + dir.first;
                    y = y + dir.second;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += gridStatus[i][j];
            }
        }
        return count;
    }
};

int main()
{
    int m, n;
    vector<vector<int>> guards;
    vector<vector<int>> walls;
    Solution sln;

    cout << sln.countUnguarded(m = 4, n = 6, guards = {{0, 0}, {1, 1}, {2, 3}}, walls = {{0, 1}, {2, 2}, {1, 4}});
    return 0;
}