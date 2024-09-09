#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topological_order(int currentNode, vector<vector<int>> &adjs, vector<int> &ref_counts)
{
    if (ref_counts[currentNode] < 0)
        return;
    cout << currentNode << " ";
    ref_counts[currentNode]--;
    for (int &nextNode : adjs[currentNode])
    {
        ref_counts[nextNode]--;
        if (ref_counts[nextNode] == 0)
        {
            topological_order(nextNode, adjs, ref_counts);
        }
    }
}

void topological_order(int &n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adjs(n);
    vector<int> ref_counts(n, 0);
    for (pair<int, int> &edge : edges)
    {
        adjs[edge.first].push_back(edge.second);
        ref_counts[edge.second]++;
    }

    for (int i = 0; i < ref_counts.size(); i++)
    {
        if (ref_counts[i] == 0)
        {
            topological_order(i, adjs, ref_counts);
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
