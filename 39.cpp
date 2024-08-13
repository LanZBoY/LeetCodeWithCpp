#include <iostream>
#include <vector>

using namespace std;

void combinationSum(vector<vector<int>> &results, vector<int> current, int startIndex, vector<int> &candidates, int target)
{
    if (target <= 0)
    {
        if (target == 0)
        {
            results.push_back(current);
        }
        return;
    }
    for (int i = startIndex; i < candidates.size(); i++)
    {
        current.push_back(candidates[i]);
        combinationSum(results, current, i, candidates, target - candidates[i]);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> results;
    combinationSum(results, {}, 0, candidates, target);
    return results;
}

int main()
{
    vector<int> candidates;
    int target;
    vector<vector<int>> results;

    candidates = {2, 3, 6, 7};
    target = 7;
    results = combinationSum(candidates, target);

    return 0;
}