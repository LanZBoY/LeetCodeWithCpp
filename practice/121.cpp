#include <iostream>
#include <vector>

using namespace std;

// recursive 1
int maxProfit(vector<int> &prices, int buyIndex, int sellIndex)
{
    if (buyIndex == 0)
    {
        return prices[sellIndex] - prices[buyIndex];
    }
    return max(
        prices[sellIndex] - prices[buyIndex],
        maxProfit(prices, buyIndex - 1, sellIndex));
}

int maxProfit(vector<int> &prices, int sellIndex)
{
    if (sellIndex == 0 || prices.empty())
    {
        return 0;
    }
    return max(
        maxProfit(prices, sellIndex - 1),
        maxProfit(prices, sellIndex - 1, sellIndex));
}

int maxProfit(vector<int> &prices)
{
    return maxProfit(prices, prices.size() - 1);
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