#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int left = 0, right;
    for (right = 0; right < nums.size(); ++right)
    {
        if (nums[right] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            k += 1 - nums[left];
            left++;
        }
    }
    return right - left;
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