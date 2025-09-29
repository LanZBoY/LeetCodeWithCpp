#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long totalCost(vector<int> &costs, int k, int candidates)
{
    priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
    int i = 0;
    int j = costs.size() - 1;

    while (pq.size() < candidates * 2)
    {
        pq.push({costs[i++], false});
        if (i > j)
            break;
        pq.push({costs[j--], true});
        if (i > j)
            break;
    }
    long long total_cost = 0;
    while (k--)
    {
        pair<int, bool> nextHire = pq.top();
        total_cost += nextHire.first;
        pq.pop();
        if (i <= j)
        {
            if (nextHire.second)
            {
                pq.push({costs[j--], true});
            }
            else
            {
                pq.push({costs[i++], false});
            }
        }
    }

    return total_cost;
}
int main()
{
    vector<int> costs;
    int k;
    int candidates;

    costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    k = 3;
    candidates = 4;
    cout << totalCost(costs, k, candidates) << endl;

    costs = {1, 2, 4, 1};
    k = 3;
    candidates = 3;
    cout << totalCost(costs, k, candidates) << endl;

    costs = {31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58};
    k = 11;
    candidates = 2;
    cout << totalCost(costs, k, candidates) << endl;

    return 0;
}