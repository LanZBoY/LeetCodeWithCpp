#include <iostream>
#include <vector>

using namespace std;

void combinationSum3(int k, int n, int start, vector<int> current, vector<vector<int>> &results)
{
    if (k == 0 || n <= 0)
    {
        if (n == 0 && k == 0)
        {
            results.push_back(current);
        }
        return;
    }

    for (int i = start; i <= 9; i++)
    {
        current.push_back(i);
        if (n - i < 0)
            continue;
        combinationSum3(k - 1, n - i, i + 1, current, results);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> results;
    combinationSum3(k, n, 1, {}, results);
    return results;
}

int main()
{
    vector<vector<int>> results;
    results = combinationSum3(3, 7);
    results = combinationSum3(3, 9);
    results = combinationSum3(4, 1);
    return 0;
}