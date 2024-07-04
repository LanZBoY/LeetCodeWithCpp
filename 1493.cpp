#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int> &nums)
{
    int removeCount = 0;
    int windowSize = 0;
    for (int i = 0; i < nums.size() && removeCount <= 1; i++)
    {
        if (nums[i] == 0)
        {
            removeCount++;
        }
        windowSize++;
    }
    int maxSize = windowSize - removeCount;
    for (int i = 0, j = windowSize; j < nums.size();)
    {
        if (removeCount > 1)
        {
            if (nums[i] == 1)
            {
                windowSize--;
            }
            else
            {
                removeCount--;
            }
            i++;
        }
        if (removeCount <= 1)
        {
            if (nums[j] == 1)
            {
                windowSize++;
            }
            else
            {
                removeCount++;
            }
            j++;
        }
        maxSize = max(maxSize, j - i - removeCount);
    }
    if (removeCount == 0)
        maxSize--;
    return maxSize;
}

int main()
{
    vector<int> data = {1, 1, 0, 1};
    cout << longestSubarray(data) << endl;
    data = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << longestSubarray(data) << endl;
    data = {1, 1, 1};
    cout << longestSubarray(data) << endl;
    return 0;
}