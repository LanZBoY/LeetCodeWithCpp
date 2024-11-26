#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> inEdgeMap(n, vector<int>());
        for (auto edge : edges)
        {
            inEdgeMap[edge[1]].push_back(edge[0]);
        }
        int result = -1;
        for (int i = 0; i < n; i++)
        {
            if (inEdgeMap[i].empty())
            {
                if (result == -1)
                {
                    result = i;
                }
                else
                {
                    return -1;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sln;
    int n;
    vector<vector<int>> edges;
    cout << sln.findChampion(n = 3, edges = {{0, 1}, {1, 2}}) << endl;
    cout << sln.findChampion(n = 4, edges = {{0, 2}, {1, 3}, {1, 2}}) << endl;
    return 0;
}