#include <iostream>
#include <vector>

using namespace std;

void dfs(int src, vector<vector<int>> &isConnected, vector<bool> &visited)
{
    if (visited[src])
        return;
    visited[src] = true;
    for (int j = 0; j < isConnected.size(); j++)
    {
        if (isConnected[src][j] && !visited[j])
        {
            dfs(j, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int count = 0;
    vector<bool> visited(isConnected.size(), false);
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, isConnected, visited);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    cout << findCircleNum(isConnected) << endl;
    return 0;
}