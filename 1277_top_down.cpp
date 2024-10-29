#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int countSquare(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if (matrix[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = countSquare(i, j + 1, dp, matrix);
        int down = countSquare(i + 1, j, dp, matrix);
        int diagonal = countSquare(i + 1, j + 1, dp, matrix);
        return dp[i][j] = 1 + min(right, min(down, diagonal));
    }

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int squareCount = 0;
        vector<vector<int>> dp(matrix.size(), vector(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                squareCount = squareCount + countSquare(i, j, dp, matrix);
            }
        }
        return squareCount;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> matrix;
    cout << sln.countSquares(matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}) << endl;
    cout << sln.countSquares(matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}) << endl;
    return 0;
}