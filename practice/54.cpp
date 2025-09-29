#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited = vector(m, vector(n, false));
        vector<int> res;
        int needToVisit = m * n;
        pair<int, int> curPoint = {0, 0};
        while (res.size() < needToVisit)
        {
            visited[curPoint.first][curPoint.second] = true;
            res.push_back(matrix[curPoint.first][curPoint.second]);
            curPoint = nextPoint(curPoint, visited);
        }
        return res;
    }

private:
    int selectDir = 0;
    const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    pair<int, int> nextPoint(pair<int, int> curPoint, vector<vector<bool>> &visited)
    {
        pair<int, int> preNext = {curPoint.first + dirs[selectDir].first, curPoint.second + dirs[selectDir].second};
        if (
            preNext.first < 0 ||
            preNext.first >= visited.size() ||
            preNext.second < 0 ||
            preNext.second >= visited[preNext.first].size() ||
            visited[preNext.first][preNext.second])
        {
            selectDir = (selectDir + 1) % 4;
            preNext = {curPoint.first + dirs[selectDir].first, curPoint.second + dirs[selectDir].second};
        }
        return preNext;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> matrix;
    vector<int> res;
    res = sln.spiralOrder(matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    res = sln.spiralOrder(matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
    return 0;
}