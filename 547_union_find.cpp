#include <iostream>
#include <vector>

using namespace std;

int findParentOpt(int x, vector<int> &parents)
{
    if (parents[x] == x)
        return x;
    return findParentOpt(parents[x], parents);
}

void unionSet(int x, int y, int &numOfCount, vector<int> &parents)
{
    int parent_x = findParentOpt(x, parents);
    int parent_y = findParentOpt(y, parents);
    if (parent_x == parent_y)
        return;
    if (parent_x < parent_y)
    {
        parents[parent_y] = parent_x;
    }
    else
    {
        parents[parent_y] = parent_x;
    }
    numOfCount--;
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int numOfCount = isConnected.size();
    vector<int> parents(isConnected.size());
    for (int i = 0; i < parents.size(); i++)
    {
        parents[i] = i;
    }
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j])
                unionSet(i, j, numOfCount, parents);
        }
    }
    return numOfCount;
}

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    cout << findCircleNum(isConnected) << endl;
    return 0;
}