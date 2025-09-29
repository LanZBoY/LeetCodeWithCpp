#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    int dfs(int &n, vector<vector<int>> &adjList)
    {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;

        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int cur = q.front();
                q.pop();

                if (cur == n - 1)
                    return step;

                for (int &adj : adjList[cur])
                {
                    if (visited[adj])
                        continue;
                    q.push(adj);
                    visited[adj] = true;
                }
            }
            step++;
        }
        return step;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> adjList(n, vector<int>());
        for (int i = 1; i < n; i++)
        {
            adjList[i - 1].push_back(i);
        }
        vector<int> result;
        for (const auto &query : queries)
        {
            adjList[query[0]].push_back(query[1]);
            result.push_back(dfs(n, adjList));
        }
        return result;
    }
};

int main()
{
    Solution sln;
    int n;
    vector<vector<int>> queries;
    vector<int> result;
    result = sln.shortestDistanceAfterQueries(n = 5, queries = {{0, 2}});
    result = sln.shortestDistanceAfterQueries(n = 5, queries = {{2, 4}, {0, 2}, {0, 4}});
    return 0;
}