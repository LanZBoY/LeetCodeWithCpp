#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int max_i = 0;
    int j = height.size() - 1;
    int max_j = 0;

    int answer = 0;

    while (i < j)
    {

        // calculate Area
        int minHeight = height[i] > height[j] ? height[j] : height[i];
        int currentArea = minHeight * (j - i);
        if (answer < currentArea)
        {
            answer = currentArea;
        }
        height[i] > height[j] ? j-- : i++;
    }
    return answer;
}

int main()
{
    vector<int> data = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(data) << endl;
    data = {1, 1};
    cout << maxArea(data) << endl;
    return 0;
}