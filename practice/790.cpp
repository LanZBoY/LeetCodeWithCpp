#include <iostream>
#include <vector>

using namespace std;

int numTilings(int n)
{
    // n = 1, 1
    // n = 2, 2
    // n = 3, 5
    // n = 4, 11
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 5;
    }
    vector<int> results = {1, 2, 5};
    for (int i = 3; i < n; i++)
        results.push_back(2 * results[i - 1] + results[i - 3]);
    return results[results.size() - 1];
}

int main()
{
    cout << numTilings(30) << endl;
    cout << numTilings(2) << endl;
    cout << numTilings(3) << endl;
    cout << numTilings(4) << endl;
    cout << numTilings(5) << endl;
    return 0;
}