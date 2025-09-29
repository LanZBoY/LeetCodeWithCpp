#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int minReorder(int n, vector<vector<int>> &connections)
{

    int count = 0;
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> toNodes;
    unordered_map<int, vector<int>> fromNodes;
    for (vector<int> connection : connections)
    {
        toNodes[connection[0]].push_back(connection[1]);
        fromNodes[connection[1]].push_back(connection[0]);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        visited[q.front()] = true;
        for (int toNode : toNodes[q.front()])
        {
            if (!visited[toNode])
            {
                count++;
                q.push(toNode);
            }
        }
        for (int fromNode : fromNodes[q.front()])
        {
            if (!visited[fromNode])
            {
                q.push(fromNode);
            }
        }
        q.pop();
    }

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