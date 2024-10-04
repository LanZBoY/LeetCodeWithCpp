#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMaxHeight(height.size(), 0);
        vector<int> rightMaxHeight(height.size(), 0);
        for (int i = 0; i < height.size(); ++i)
        {
            if (i == 0)
            {
                leftMaxHeight[i] = height[i];
                rightMaxHeight[height.size() - i - 1] = height[height.size() - i - 1];
            }
            else
            {
                leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i]);
                rightMaxHeight[height.size() - i - 1] = max(rightMaxHeight[height.size() - i], height[height.size() - i - 1]);
            }
        }
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            res += (min(leftMaxHeight[i], rightMaxHeight[i]) - height[i]);
        }
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> height;
    cout << sln.trap(height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;
    cout << sln.trap(height = {4, 2, 0, 3, 2, 5}) << endl;
    cout << sln.trap(height = {4, 2, 3}) << endl;
    return 0;
}