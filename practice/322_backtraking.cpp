#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtraking(int time, int cAmount, int &minTime, vector<int> &coins)
    {
        if (cAmount == 0)
        {
            minTime = min(time, minTime);
            return;
        }
        if (cAmount < 0)
            return;
        for (int &coin : coins)
        {
            backtraking(time + 1, cAmount - coin, minTime, coins);
        }
    }
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        int minTime = INT_MAX;
        for (int &coin : coins)
        {
            backtraking(1, amount - coin, minTime, coins);
        }
        return minTime == INT_MAX ? -1 : minTime;
    }
};

int main()
{
    Solution sln;
    vector<int> coins;
    int amount;

    coins = {1, 2, 5};
    amount = 11;
    cout << sln.coinChange(coins, amount) << endl;

    coins = {2};
    amount = 3;
    cout << sln.coinChange(coins, amount) << endl;

    return 0;
}