#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix;
    Solution sln;
    sln.rotate(matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    sln.rotate(matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
    return 0;
}