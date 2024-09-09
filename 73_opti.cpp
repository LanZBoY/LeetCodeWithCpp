#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<bool> zeroRows(matrix.size(), false);
        vector<bool> zeroCols(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (zeroRows[i] || zeroCols[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> matrix;
    sln.setZeroes(matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
    sln.setZeroes(matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}});
    return 0;
}