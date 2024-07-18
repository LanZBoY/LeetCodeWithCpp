#include <iostream>
#include <vector>

using namespace std;

int findParent(int x, vector<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    return findParent(parent[x], parent);
}

void unionSet(int x, int y, vector<int> &parent)
{
    int parent_x = findParent(x, parent);
    int parent_y = findParent(y, parent);
    if (parent_x == parent_y)
        return;
    if (parent_x < parent_y)
    {
        parent[parent_y] = parent_x;
    }
    else
    {
        parent[parent_x] = parent_y;
    }
}

int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {4, 5}, {4, 3}};
    int numOfNode = 6;
    vector<int> parent(numOfNode);
    for (int i = 0; i < numOfNode; i++)
    {
        parent[i] = i;
    }
    for (pair<int, int> edge : edges)
    {
        unionSet(edge.first, edge.second, parent);
    }
    for (int i = 0; i < numOfNode; i++)
    {
        cout << findParent(i, parent) << endl;
    }
    return 0;
}