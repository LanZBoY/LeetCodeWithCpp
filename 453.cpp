#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int shotCount = 1;
    int endPoint = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        vector<int> currentPoint = points[i];
        if (currentPoint[0] > endPoint)
        {
            endPoint = currentPoint[1];
            shotCount++;
        }
    }
    return shotCount;
}

int main()
{
    vector<vector<int>> points;

    points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points) << endl;

    points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << findMinArrowShots(points) << endl;

    points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << findMinArrowShots(points) << endl;

    return 0;
}