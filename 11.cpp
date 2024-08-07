#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int maxArea = 0;
    while (i < j)
    {
        maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        height[i] > height[j] ? j-- : i++;
    }
    return maxArea;
}

int main()
{
    vector<int> data = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(data) << endl;
    data = {1, 1};
    cout << maxArea(data) << endl;
    return 0;
}