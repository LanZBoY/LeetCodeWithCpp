#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> counter;
    for (int num : nums)
    {
        counter[num]++;
    }

    auto comp = [](pii &a, pii &b)
    {
        return a.second < b.second;
    };

    priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
    for (pii p : counter)
    {
        pq.push(p);
    }
    vector<int> res(k);
    for (int i = 0; i < k; i++)
    {
        res[i] = pq.top().first;
        pq.pop();
    }
    return res;
}

int main()
{
    vector<int> nums;
    int k;
    vector<int> res;

    nums = {1, 1, 1, 2, 2, 3};
    k = 2;
    res = topKFrequent(nums, k);

    nums = {1};
    k = 1;
    res = topKFrequent(nums, k);

    return 0;
}