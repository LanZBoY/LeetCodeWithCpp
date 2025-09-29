#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(int currentNode, int prevNode, vector<vector<int>> &adjs, unordered_set<int> &visitedSet)
{
    if (visitedSet.find(currentNode) != visitedSet.end())
        return false;
    visitedSet.insert(currentNode);
    for (int &nextNode : adjs[currentNode])
    {
        if (prevNode == -1 || nextNode != prevNode)
        {
            if (!dfs(nextNode, currentNode, adjs, visitedSet))
            {
                return false;
            }
        }
    }
    return true;
}

bool validTree(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adjs(n);
    for (vector<int> &edge : edges)
    {
        adjs[edge[0]].push_back(edge[1]);
        adjs[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> visitedSet;

    return dfs(0, -1, adjs, visitedSet) && visitedSet.size() == n;
}

int main()
{
    int n;
    vector<vector<int>> edges;

    n = 5;
    edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << validTree(n, edges) << endl;

    n = 5;
    edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << validTree(n, edges) << endl;

    return 0;
}