#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> results;
    for (int spell : spells)
    {
        int i = 0;
        int j = potions.size() - 1;
        while (i <= j)
        {
            int currentPosition = (i + j) / 2;
            int potion = potions[currentPosition] * spell;
            if (potion >= success)
            {
                j = currentPosition - 1;
            }
            else if (potion < success)
            {
                i = currentPosition + 1;
            }
        }
        results.push_back(potions.size() - i);
    }
    return results;
}

int main()
{
    vector<int> spells;
    vector<int> potions;
    long long success;
    vector<int> result;

    spells = {5, 1, 3};
    potions = {1, 2, 3, 4, 5};
    success = 7;
    result = successfulPairs(spells, potions, success);

    spells = {3, 1, 2};
    potions = {8, 5, 8};
    success = 16;
    result = successfulPairs(spells, potions, success);

    spells = {7};
    potions = {1, 1, 1, 1, 1, 1, 2};
    success = 7;
    result = successfulPairs(spells, potions, success);
    return 0;
}