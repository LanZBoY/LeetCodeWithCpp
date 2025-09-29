
/*
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
1. increase your score by nums[i], and
2. replace nums[i] with ceil(nums[i] / 3).
3. Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
    Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
    Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
    Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
    The final score is 10 + 4 + 3 = 17.
*/

// use PQ to maintain the max value
// take value from the top of PQ (let it be x), then apply sum with score and x = ceil(x / 3)
// push x back to the pq
// time complexity is O(N + logN)

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        auto cmp = [](int &a, int &b)
        {
            return a < b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(nums.begin(), nums.end(), cmp);
        long long res = 0;
        while (pq.top() != 0 && k--)
        {
            int cur = pq.top();
            res += cur;
            cur = ceil(cur / 3.);
            pq.pop();
            pq.push(cur);
        }
        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int k;
    cout << sln.maxKelements(nums = {10, 10, 10, 10, 10}, k = 5) << endl;
    cout << sln.maxKelements(nums = {1, 10, 3, 3, 3}, k = 3) << endl;
    return 0;
}