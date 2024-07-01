#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        maxSum += nums[i];
    }
    int sum = maxSum;
    for (int i = 0; i < nums.size() - k; i++)
    {
        sum = sum - nums[i] + nums[i + k];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }
    return (double)maxSum / k;
}

int main()
{
    vector<int> data = {1, 12, -5, -6, 50, 3};
    cout << findMaxAverage(data, 4) << endl;
    data = {-1};
    cout << findMaxAverage(data, 1) << endl;
    data = {0, 1, 1, 3, 3};
    cout << findMaxAverage(data, 4) << endl;
    data = {0, 4, 0, 3, 2};
    cout << findMaxAverage(data, 1) << endl;
    return 0;
}