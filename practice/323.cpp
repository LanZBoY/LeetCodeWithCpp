#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int> &unionSet, int a)
{
    if (unionSet[a] < 0)
    {
        return a;
    }
    return unionSet[a] = findParent(unionSet, unionSet[a]);
}

bool joinSet(vector<int> &unionSet, int a, int b)
{
    int parent_a = findParent(unionSet, a);
    int parent_b = findParent(unionSet, b);
    if (parent_a == parent_b)
    {
        return false;
    }
    if (-unionSet[parent_a] > -unionSet[parent_b])
    {
        unionSet[parent_a] += unionSet[parent_b];
        unionSet[parent_b] = parent_a;
        return true;
    }
    unionSet[parent_b] += unionSet[parent_a];
    unionSet[parent_a] = parent_b;
    return true;
}

int countComponents(int n, vector<vector<int>> &edges)
{
    vector<int> unionSet(n, -1);
    int count = n;
    for (vector<int> &edge : edges)
    {
        if (joinSet(unionSet, edge[0], edge[1]))
        {
            count--;
        }
    }
    return count;
}

int main()
{
    int n;
    vector<vector<int>> edges;

    n = 3;
    edges = {{0, 1}, {0, 2}};
    cout << countComponents(n, edges) << endl;

    n = 6;
    edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << countComponents(n, edges) << endl;
    return 0;
}