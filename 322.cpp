#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> amounts(amount + 1, -1);

        amounts[0] = 0;

        for (int i = 1; i < amounts.size(); i++)
        {
            int minValue = -1;
            for (int &coin : coins)
            {
                if (i >= coin && amounts[i - coin] >= 0)
                {
                    if (minValue == -1)
                    {
                        minValue = amounts[i - coin] + 1;
                    }
                    else
                    {
                        minValue = min(minValue, amounts[i - coin] + 1);
                    }
                }
            }
            amounts[i] = minValue;
        }
        return amounts[amounts.size() - 1];
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