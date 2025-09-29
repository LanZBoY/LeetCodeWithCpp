#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!dms.empty() && dms.top().first <= price)
        {
            span += dms.top().second;
            dms.pop();
        }
        dms.push({price, span});
        return span;
    }

private:
    stack<pair<int, int>> dms;
};

int main()
{
    StockSpanner stockSpanner;
    vector<int> inputArray = {28, 14, 28, 35, 46, 53, 66, 80, 87, 88};
    for (int num : inputArray)
    {
        cout << stockSpanner.next(num) << endl;
    }
    return 0;
}