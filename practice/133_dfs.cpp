#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *constructGraph(vector<vector<int>> edges)
{
    if (edges.empty())
    {
        return nullptr;
    }
    vector<Node *> nodeList(edges.size(), nullptr);
    for (int i = 0; i < nodeList.size(); i++)
    {
        nodeList[i] = new Node(i + 1);
    }
    for (int i = 0; i < edges.size(); i++)
    {
        for (int nodeId : edges[i])
        {
            nodeList[i]->neighbors.push_back(nodeList[nodeId - 1]);
        }
    }
    return nodeList[0];
}

Node *dfs(Node *node, unordered_map<Node *, Node *> &mapToNew)
{
    if (mapToNew.find(node) != mapToNew.end())
        return mapToNew[node];
    mapToNew[node] = new Node(node->val);
    for (Node *nextNode : node->neighbors)
    {
        mapToNew[node]->neighbors.push_back(dfs(nextNode, mapToNew));
    }
    return mapToNew[node];
}

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
        return nullptr;
    unordered_map<Node *, Node *> mapToNew;

    mapToNew[node] = new Node(node->val);
    for (Node *nextNode : node->neighbors)
    {
        mapToNew[node]->neighbors.push_back(dfs(nextNode, mapToNew));
    }
    return mapToNew[node];
}

int main()
{
    Node *srcNode, *cloneNode;
    srcNode = constructGraph({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
    cloneNode = cloneGraph(srcNode);

    srcNode = constructGraph({{}});
    cloneNode = cloneGraph(srcNode);

    srcNode = constructGraph({});
    cloneNode = cloneGraph(srcNode);
    return 0;
}