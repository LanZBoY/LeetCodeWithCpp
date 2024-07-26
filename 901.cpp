#include <iostream>
#include <vector>

using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        datas.push_back(price);
        int span = 1;
        for (int i = datas.size() - 2; i >= 0; i--)
        {
            if (datas[i] <= price)
                span++;
            else
                break;
        }
        return span;
    }

private:
    vector<int> datas;
};

int main()
{

    return 0;
}