#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int holds[prices.size()];
    int cashs[prices.size()];
    holds[0] = -prices[0]; // 如果一開始為持有狀態的話，代表會先有一筆成本
    cashs[0] = 0;          // 要有購買才會有販賣，所以開始的利潤為0
    for (int i = 1; i < prices.size(); i++)
    {
        holds[i] = max(holds[i - 1], cashs[i - 1] - prices[i]);

        cashs[i] = max(cashs[i - 1], holds[i - 1] + prices[i] - fee);
    }
    return cashs[prices.size() - 1];
}

int main()
{
    vector<int> prices;
    int fee;
    prices = {1, 3, 2, 8, 4, 9};
    fee = 2;
    cout << maxProfit(prices, fee) << endl;

    prices = {1, 3, 7, 5, 10, 3};
    fee = 3;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}