#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

using psi = pair<string, int>;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    auto comp = [](psi &a, psi &b)
    {
        return a.second < b.second;
    };
    priority_queue<psi, vector<psi>, decltype(comp)> pq(comp);
    for (int i = 0; i < names.size(); i++)
    {
        pq.push({names[i], heights[i]});
    }
    vector<string> results(names.size());
    int i = 0;
    while (!pq.empty())
    {
        results[i++] = pq.top().first;
        pq.pop();
    }
    return results;
}

int main()
{
    vector<string> names;
    vector<int> heights;
    vector<string> results;

    names = {"Mary", "John", "Emma"};
    heights = {180, 165, 170};
    results = sortPeople(names, heights);

    names = {"Alice", "Bob", "Bob"};
    heights = {155, 185, 150};
    results = sortPeople(names, heights);

    return 0;
}