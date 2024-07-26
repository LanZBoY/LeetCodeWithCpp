#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int buys[prices.size()];
    int sells[prices.size()];
    buys[0] = prices[0];
    sells[0] = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        buys[i] = min(prices[i], buys[i - 1]);
        sells[i] = max(sells[i - 1], prices[i] - buys[i]);
    }
    return sells[prices.size() - 1];
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