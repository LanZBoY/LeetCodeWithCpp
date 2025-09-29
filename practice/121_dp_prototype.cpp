#include <iostream>
#include <vector>

using namespace std;

int minBuy(vector<int> &prices, int buyIndex, vector<int> &minBuys)
{
    if (minBuys[buyIndex] != INT_MAX)
    {
        return minBuys[buyIndex];
    }
    if (buyIndex == 0)
    {
        minBuys[buyIndex] = prices[buyIndex];
        return minBuys[buyIndex];
    }
    minBuys[buyIndex] = min(prices[buyIndex], minBuy(prices, buyIndex - 1, minBuys));
    return minBuys[buyIndex];
}

int maxProfit(vector<int> &prices, int sellIndex, vector<int> &minBuys)
{
    if (prices.empty() || sellIndex == 0)
    {
        return 0;
    }
    return max(maxProfit(prices, sellIndex - 1, minBuys), prices[sellIndex] - minBuy(prices, sellIndex - 1, minBuys));
}

int maxProfit(vector<int> &prices)
{
    vector<int> minBuys(prices.size(), INT_MAX);
    return maxProfit(prices, prices.size() - 1, minBuys);
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