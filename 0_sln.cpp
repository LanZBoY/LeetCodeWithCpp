#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> buyStatus(prices.size(), 0);
        vector<int> sellStatus(prices.size(), 0);
        buyStatus[0] = -prices[0]; // from prev buyStatus or sellStatus buy current stock price
        sellStatus[0] = 0;         // from prev sellStatus or buyStatus sell current stock price
        for (int i = 1; i < prices.size(); i++)
        {
            buyStatus[i] = max(buyStatus[i - 1], sellStatus[i - 1] - prices[i]);
            sellStatus[i] = max(sellStatus[i - 1], buyStatus[i - 1] + prices[i]);
        }
        return sellStatus[prices.size() - 1];
    }
};
int main()
{
    Solution sln;
    vector<int> prices;
    cout << sln.maxProfit(prices = {7, 1, 5, 3, 6, 4}) << endl;
    cout << sln.maxProfit(prices = {1, 2, 3, 4, 5}) << endl;
    cout << sln.maxProfit(prices = {7, 6, 4, 3, 1}) << endl;
    return 0;
}