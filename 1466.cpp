#include <iostream>
#include <vector>

using namespace std;

void dfs(int src, vector<vector<int>> &connections, vector<bool> &visited, int &count)
{
    visited[src] = true;
    for (vector<int> connection : connections)
    {
        if (!visited[connection[0]] || !visited[connection[1]])
        {

            if (connection[0] == src)
            {
                count++;
                dfs(connection[1], connections, visited, count);
            }
            if (connection[1] == src)
            {
                dfs(connection[0], connections, visited, count);
            }
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections)
{
    vector<bool> visited(n, false);
    int count = 0;
    dfs(0, connections, visited, count);
    return count;
}

int main()
{
    int n = 6;
    vector<vector<int>> connection = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    minReorder(n, connection);
    n = 5;
    connection = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    minReorder(n, connection);
    n = 6;
    connection = {{0, 3}, {0, 1}, {0, 2}, {4, 0}, {4, 5}};
    minReorder(n, connection);
    return 0;
}