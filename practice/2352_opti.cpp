#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int equalPairs(vector<vector<int>> &grid)
{
    const int n = grid.size();
    map<vector<int>, int> rowMap;

    for (int row = 0; row < n; row++)
    {
        rowMap[grid[row]]++;
    }
    int ans = 0;
    for (int col = 0; col < n; col++)
    {
        vector<int> grid_col(n);
        for (int row = 0; row < n; row++)
        {
            grid_col[row] = grid[row][col];
        }

        ans += rowMap[grid_col];
    }
    return ans;
}

int equalPairs_0(vector<vector<int>> &grid)
{
    unordered_map<string, int> rowMap;
    unordered_map<string, int> colMap;
    for (int i = 0; i < grid.size(); i++)
    {
        string rowString = "";
        string colString = "";
        for (int j = 0; j < grid[i].size(); j++)
        {
            rowString += to_string(grid[i][j]) + ",";
            colString += to_string(grid[j][i]) + ",";
        }
        rowMap[rowString]++;
        colMap[colString]++;
    }
    int result = 0;
    for (auto data : rowMap)
    {
        result += (rowMap[data.first] * colMap[data.first]);
    }
    return result;
}

int main()
{
    vector<vector<int>> data = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    cout << equalPairs(data) << endl;
    data = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    cout << equalPairs(data) << endl;
    data = {{13, 13}, {13, 13}};
    cout << equalPairs(data) << endl;
    return 0;
}