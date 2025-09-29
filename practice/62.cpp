#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> grids;
    for (int i = 0; i < m; i++)
    {
        vector<int> tmp;
        if (i == 0)
        {
            tmp = vector(n, 1);
        }
        else
        {
            tmp = vector(n, 0);
            tmp[0] = 1;
        }
        grids.push_back(tmp);
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grids[i][j] = grids[i - 1][j] + grids[i][j - 1];
        }
    }
    return grids[m - 1][n - 1];
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    cout << uniquePaths(3, 2) << endl;
    return 0;
}