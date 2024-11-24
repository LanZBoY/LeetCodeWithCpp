#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        long long ans = 0;
        int neg_counter = 0;
        int close_to_zero = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int preSum = matrix[i][j];
                if (matrix[i][j] <= 0)
                {
                    preSum = -preSum;
                    neg_counter++;
                }
                close_to_zero = min(close_to_zero, preSum);
                ans += preSum;
            }
        }
        if (neg_counter % 2 == 1)
        {
            ans -= (close_to_zero * 2);
        }
        return ans;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> matrix;
    // cout << sln.maxMatrixSum(matrix = {
    //                              {1, 2, 3},
    //                              {-1, -2, -3},
    //                              {1, 2, 3},
    //                          })
    //      << endl;
    // cout << sln.maxMatrixSum(matrix = {
    //                              {-1, 0, -1},
    //                              {-2, 1, 3},
    //                              {3, 2, 2},
    //                          })
    //      << endl;

    cout << sln.maxMatrixSum(matrix = {
                                 {2, 9, 3},
                                 {5, 4, -4},
                                 {1, 7, 1},
                             })
         << endl;
    return 9;
}