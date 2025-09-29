#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (zeroRows.find(i) != zeroRows.end() || zeroCols.find(j) != zeroCols.end())
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