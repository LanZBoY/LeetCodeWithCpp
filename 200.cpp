#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int findParent(int node, vector<int> &nodes)
{
    if (nodes[node] < 0)
    {
        return node;
    }
    return nodes[node] = findParent(nodes[node], nodes);
}

void unionNodeSet(int node_x, int node_y, vector<int> &nodes, unordered_set<int> &islandSet)
{
    int parent_x = findParent(node_x, nodes);
    int parent_y = findParent(node_y, nodes);
    if (parent_x == parent_y)
        return;
    if (-nodes[parent_x] < -nodes[parent_y])
    {
        int tmp = parent_x;
        parent_x = parent_y;
        parent_y = tmp;
    }
    nodes[parent_x] += nodes[parent_y];
    nodes[parent_y] = parent_x;
    islandSet.insert(parent_x);
    if (islandSet.find(parent_y) != islandSet.end())
    {
        islandSet.erase(parent_y);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    // m x n
    int m = grid.size();
    int n = grid[0].size();
    vector<int> nodes(m * n, -1);
    unordered_set<int> islandSet;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != '1')
                continue;
            bool isIsolate = true;
            if ((i + 1 < m) && grid[i + 1][j] == '1')
            {
                unionNodeSet(i * n + j, (i + 1) * n + j, nodes, islandSet);
                isIsolate = false;
            }
            if ((i - 1 >= 0) && grid[i - 1][j] == '1')
            {
                unionNodeSet(i * n + j, (i - 1) * n + j, nodes, islandSet);
                isIsolate = false;
            }
            if ((j + 1 < n) && grid[i][j + 1] == '1')
            {
                unionNodeSet(i * n + j, i * n + (j + 1), nodes, islandSet);
                isIsolate = false;
            }
            if ((j - 1 >= 0) && grid[i][j - 1] == '1')
            {
                unionNodeSet(i * n + j, i * n + (j - 1), nodes, islandSet);
                isIsolate = false;
            }
            if (isIsolate)
            {
                islandSet.insert(i * n + j);
            }
        }
    }
    return islandSet.size();
}
int main()
{
    // vector<vector<char>> grid = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}};
    // cout << numIslands(grid) << endl;
    // grid = {
    //     {'1', '1', '0', '0', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '1', '0', '0'},
    //     {'0', '0', '0', '1', '1'}};
    // cout << numIslands(grid) << endl;
    vector<vector<char>> grid = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}