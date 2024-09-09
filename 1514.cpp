#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <math.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<pair<int, double>>> adjs;
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> &edge = edges[i];
            double &prob = succProb[i];
            adjs[edge[0]].push_back({edge[1], -log(prob)});
            adjs[edge[1]].push_back({edge[0], -log(prob)});
        }

        vector<double> fromA(n, 0xffffffffffffffff);
        unordered_set<int> visited;
        auto comp = [](pair<int, double> a, pair<int, double> b)
        {
            return a.second > b.second;
        };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(comp)> pq(comp);

        pq.push({start_node, 0.0});
        fromA[start_node] = 0;
        visited.insert(start_node);
        while (!pq.empty())
        {
            pair<int, double> curr = pq.top();
            pq.pop();
            for (pair<int, double> neiNode : adjs[curr.first])
            {
                fromA[neiNode.first] = min(fromA[neiNode.first], fromA[curr.first] + neiNode.second);
                if (visited.find(neiNode.first) == visited.end())
                {
                    pq.push({neiNode.first, fromA[neiNode.first]});
                    visited.insert(neiNode.first);
                }
            }
        }
        return exp(-fromA[end_node]);
    }
};

int main()
{
    Solution sln;

    int n, start_node, end_node;
    vector<vector<int>> edges;
    vector<double> succProb;

    cout << sln.maxProbability(n = 3,
                               edges = {{0, 1}, {1, 2}, {0, 2}},
                               succProb = {0.5, 0.5, 0.2},
                               start_node = 0,
                               end_node = 2)
         << "\n";

    cout << sln.maxProbability(n = 3,
                               edges = {{0, 1}, {1, 2}, {0, 2}},
                               succProb = {0.5, 0.5, 0.3},
                               start_node = 0,
                               end_node = 2)
         << "\n";

    cout << sln.maxProbability(n = 3,
                               edges = {{0, 1}},
                               succProb = {0.5},
                               start_node = 0,
                               end_node = 2)
         << "\n";

    cout << sln.maxProbability(n = 5,
                               edges = {{2, 3}, {1, 2}, {3, 4}, {1, 3}, {1, 4}, {0, 1}, {2, 4}, {0, 4}, {0, 2}},
                               succProb = {0.06, 0.26, 0.49, 0.25, 0.2, 0.64, 0.23, 0.21, 0.77},
                               start_node = 0,
                               end_node = 3)
         << "\n";

        return 0;
}