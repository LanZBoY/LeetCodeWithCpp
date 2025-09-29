#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        int reuslt = INT_MAX;
        long long cumulativeSum = 0;

        // Always return minmum prefix sum
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefixSumHeap;

        for (int i = 0; i < n; i++)
        {
            cumulativeSum += nums[i];

            if (cumulativeSum >= k)
            {
                reuslt = min(reuslt, i + 1);
            }

            while (!prefixSumHeap.empty() && cumulativeSum - prefixSumHeap.top().first >= k)
            {
                reuslt = min(reuslt, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }

            prefixSumHeap.emplace(cumulativeSum, i);
        }
        return reuslt == INT_MAX ? -1 : reuslt;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    // cout << sln.shortestSubarray(nums = {1}, k = 1) << endl;
    // cout << sln.shortestSubarray(nums = {1, 2}, k = 4) << endl;
    cout << sln.shortestSubarray(nums = {2, -1, 2}, k = 3) << endl;
    return 0;
}