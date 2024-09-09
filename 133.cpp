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

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    unordered_set<Node *> src_visited;
    queue<Node *> src_q;

    unordered_map<int, Node *> cloneNodeIds;
    src_visited.insert(node);
    src_q.push(node);
    cloneNodeIds[node->val] = new Node(node->val);
    Node *startNode = cloneNodeIds[src_q.front()->val];
    while (!src_q.empty())
    {
        Node *currentNode = cloneNodeIds[src_q.front()->val];
        for (Node *srcNode : src_q.front()->neighbors)
        {
            if (src_visited.find(srcNode) == src_visited.end())
            {
                src_visited.insert(srcNode);
                cloneNodeIds[srcNode->val] = new Node(srcNode->val);
                src_q.push(srcNode);
            }
            currentNode->neighbors.push_back(cloneNodeIds[srcNode->val]);
        }
        src_q.pop();
    }
    return startNode;
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