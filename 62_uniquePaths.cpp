#include <iostream>

using namespace std;

int uniquePaths(int m, int n)
{
    // 3 x 7 rrrrrrdd
    int array[m][n];
    for (int i = 0; i < m; i++)
    {
        array[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        array[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            array[i][j] = array[i - 1][j] + array[i][j - 1];
        }
    }
    return array[m - 1][n - 1];
}

int main()
{
    uniquePaths(3, 7);
    return 0;
}