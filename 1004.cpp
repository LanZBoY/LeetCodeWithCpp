#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int placedZeroNum = 0;
    int j = 0;

    while (placedZeroNum < k && j < nums.size())
    {
        if (nums[j] == 0)
        {
            placedZeroNum++;
        }
        j++;
    }
    int i = 0;
    int maxWindowSize = j - i;
    while (j < nums.size())
    {
        if (placedZeroNum <= k)
        {
            if (nums[j] == 0)
            {
                placedZeroNum++;
            }
            j++;
        }
        if (placedZeroNum > k)
        {
            if (nums[i++] == 0)
            {
                placedZeroNum--;
            }
            else
            {
                continue;
            }
        }
        maxWindowSize = max(maxWindowSize, j - i);
    }
    return maxWindowSize;
}

int main()
{
    vector<int> data = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << longestSubarray(data, 2) << endl;
    data = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestSubarray(data, 3) << endl;
    data = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestSubarray(data, 0) << endl;
    return 0;
}