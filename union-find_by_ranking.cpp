#include <iostream>
#include <vector>

using namespace std;

int findParent(int x, vector<int> &parents)
{
    if (parents[x] < 0)
    {
        return x;
    }
    return findParent(parents[x], parents);
}

// 在找的過程中指向最終的父節點
int findParentOpt(int x, vector<int> &parents)
{
    if (parents[x] < 0)
    {
        return x;
    }
    return parents[x] = findParentOpt(parents[x], parents);
}

void unionSet(int x, int y, vector<int> &parents)
{
    int parent_x = findParentOpt(x, parents);
    int parent_y = findParentOpt(y, parents);
    if (parent_x == parent_y)
        return;
    if (-parents[parent_x] < -parents[parent_y])
    {
        parents[parent_y] += parents[parent_x];
        parents[parent_x] = parent_y;
        return;
    }
    parents[parent_x] += parents[parent_y];
    parents[parent_y] = parent_x;
}

int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {4, 5}, {4, 3}, {0, 4}};
    int numOfNode = 6;
    vector<int> parents(numOfNode, -1);
    vector<int> ranks(numOfNode, 1);
    for (pair<int, int> edge : edges)
    {
        unionSet(edge.first, edge.second, parents);
    }
    for (int i = 0; i < numOfNode; i++)
    {
        cout << findParentOpt(i, parents) << endl;
    }
    return 0;
}