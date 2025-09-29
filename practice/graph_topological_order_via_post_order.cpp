#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum NodeState
{
    unvisited,
    visiting,
    visisted,
};

bool topological_order(int currentNode, vector<vector<int>> &adjs, vector<NodeState> &nodeStatus)
{
    if (nodeStatus[currentNode] == visiting)
        return true;
    if (nodeStatus[currentNode] == visisted)
        return false;
    nodeStatus[currentNode] = visiting;
    for (int &nextNode : adjs[currentNode])
    {
        if (topological_order(nextNode, adjs, nodeStatus))
        {
            return true;
        }
    }
    nodeStatus[currentNode] = visisted;
    cout << currentNode << " ";
    return false;
}

void topological_order(int &n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adjs(n);
    for (pair<int, int> &edge : edges)
    {
        adjs[edge.first].push_back(edge.second);
    }
    vector<NodeState> nodeStatus(n, unvisited);
    for (int i = 0; i < nodeStatus.size(); i++)
    {
        if (topological_order(i, adjs, nodeStatus))
        {
            cout << "CY" << endl;
        }
    }
    cout << endl;
}

int main()
{
    int n = 9;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 5}, {3, 6}, {4, 7}, {4, 8}, {5, 4}, {5, 8}, {6, 7}, {8, 7}};
    topological_order(n, edges);
    return 0;
}
