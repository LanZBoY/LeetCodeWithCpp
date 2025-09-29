#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct GraphNode
{
    string nodeName;
    unordered_map<string, int> adj;
};

class WeightedGraph
{
public:
    GraphNode getNode(string name)
    {
        return nodeSet[name];
    }

    void addNode(string name)
    {
        GraphNode node{.nodeName = name};
        nodeSet[name] = node;
    }

    void addNodes(vector<string> addSet)
    {
        for (string &name : addSet)
        {
            GraphNode node{.nodeName = name};
            nodeSet[name] = node;
        }
    }

    void addEdge(string a, string b, int weight)
    {
        nodeSet[a].adj.insert({b, weight});
        nodeSet[b].adj.insert({a, weight});
    }

    int size()
    {
        return nodeSet.size();
    }

    GraphNode operator[](string name)
    {
        return nodeSet[name];
    }

private:
    unordered_map<string, GraphNode> nodeSet;
};

void Shortest_Path_Between(WeightedGraph &g, string start, string end)
{
    unordered_set<string> visited;
    unordered_map<string, int> SFS; // shortest from start table
    unordered_map<string, string> prev;
    auto comp = [](pair<string, int> &a, pair<string, int> b)
    {
        return a.second > b.second;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
    string current = start;
    SFS.insert({start, 0});
    pq.push({start, 0});
    while (visited.size() < g.size())
    {
        current = pq.top().first;
        pq.pop();
        visited.insert(current);
        for (pair<string, int> adj : g[current].adj)
        {
            if (visited.find(adj.first) != visited.end())
                continue;
            if (SFS.find(adj.first) == SFS.end() ||
                SFS[current] + adj.second < SFS[adj.first])
            {
                SFS[adj.first] = SFS[current] + adj.second;
                prev[adj.first] = current;
                pq.push({adj.first, SFS[adj.first]});
            }
        }
    }
}

int main()
{
    WeightedGraph g;

    g.addNodes({"A", "B", "C", "D", "E", "F"});

    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "E", 3);
    g.addEdge("C", "D", 2);
    g.addEdge("C", "F", 4);
    g.addEdge("D", "F", 1);
    g.addEdge("D", "E", 3);
    g.addEdge("F", "E", 1);

    Shortest_Path_Between(g, "A", "E");
    return 0;
}
