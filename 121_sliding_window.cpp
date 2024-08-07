#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int i = 0;
    int minBuy = prices[i];
    int maxProfit = 0;
    while (i < prices.size())
    {
        if (minBuy > prices[i])
        {
            minBuy = prices[i];
        }
        maxProfit = max(maxProfit, prices[i] - minBuy);
        i++;
    }

    return maxProfit;
}

int main()
{
    vector<int> prices;
    prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    return 0;
}