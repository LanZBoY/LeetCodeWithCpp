#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    vector<int> results = {0, 1, 1};
    for (int i = 2; i < n; i++)
    {
        results.push_back(results[i] + results[i - 1] + results[i - 2]);
    }
    return results[results.size() - 1];
}

int main()
{
    cout << tribonacci(4) << endl;
    cout << tribonacci(25) << endl;
    return 0;
}