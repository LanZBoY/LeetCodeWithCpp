#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

void searchResult(string startNode,
                  string endNode,
                  double result,
                  unordered_set<string> &searchedSet,
                  unordered_map<string, vector<pair<string, double>>> &toNodes,
                  vector<double> &results,
                  bool &find,
                  unordered_set<string> &nodeSet)
{
    if (startNode == endNode)
    {
        if (nodeSet.find(startNode) != nodeSet.end())
        {
            results.push_back(result);
            find = true;
        }
        return;
    }
    searchedSet.insert(startNode);
    for (pair<string, double> toNode : toNodes[startNode])
    {
        if (!find)
        {
            if (searchedSet.find(toNode.first) == searchedSet.end())
            {
                searchResult(toNode.first, endNode, result * toNode.second, searchedSet, toNodes, results, find, nodeSet);
            }
        }
    }
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<double> results;
    unordered_map<string, vector<pair<string, double>>> toNodes;
    unordered_set<string> nodeSet;
    for (int i = 0; i < equations.size(); i++)
    {
        vector<string> equation = equations[i];
        toNodes[equation[0]].push_back({equation[1], values[i]});
        toNodes[equation[1]].push_back({equation[0], 1 / values[i]});
        nodeSet.insert(equation[0]);
        nodeSet.insert(equation[1]);
    }
    for (vector<string> query : queries)
    {
        unordered_set<string> searchedSet;
        bool find = false;
        searchResult(query[0], query[1], 1.0, searchedSet, toNodes, results, find, nodeSet);
        if (!find)
        {
            results.push_back(-1.0);
        }
    }
    return results;
}

int main()
{
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    vector<double> result;
    // equations = {{"a", "b"}, {"b", "c"}};
    // values = {2.0, 3.0};
    // queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    // result = calcEquation(equations, values, queries);

    // equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    // values = {1.5, 2.5, 5.0};
    // queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    // result = calcEquation(equations, values, queries);

    // equations = {{"a", "b"}};
    // values = {0.5};
    // queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    // result = calcEquation(equations, values, queries);
    equations = {{"a", "b"}, {"b", "c"}, {"a", "c"}};
    values = {2.0, 3.0, 6.0};
    queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    result = calcEquation(equations, values, queries);
    return 0;
}