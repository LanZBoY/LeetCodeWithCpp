#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

using pii = pair<int, int>;
vector<int> frequencySort(vector<int> &nums)
{
    auto cmparter = [](pii l, pii r)
    {
        if (l.second == r.second)
        {
            return l.first < r.first;
        }
        return l.second > r.second;
    };

    unordered_map<int, int> frequencyMap;

    for (int num : nums)
    {
        frequencyMap[num]++;
    }

    priority_queue<pii, vector<pii>, decltype(cmparter)> pq(cmparter);

    for (pii f : frequencyMap)
    {
        pq.push(f);
    }
    vector<int> results(nums.size());
    int i = 0;
    while (!pq.empty())
    {
        pii current = pq.top();
        results[i++] = current.first;
        pq.pop();
        if (current.second - 1 != 0)
        {
            pq.push({current.first, current.second - 1});
        }
    }
    return results;
}

int main()
{
    vector<int> nums;
    vector<int> results;
    nums = {1, 1, 2, 2, 2, 3};
    results = frequencySort(nums);

    return 0;
}