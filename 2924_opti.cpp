#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<bool> hasInEdge(n, false);
        for (auto edge : edges)
        {
            hasInEdge[edge[1]] = true;
        }
        int result = -1;
        for (int i = 0; i < n; i++)
        {
            if (!hasInEdge[i])
            {
                if (result != -1)
                {
                    return -1;
                }
                result = i;
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