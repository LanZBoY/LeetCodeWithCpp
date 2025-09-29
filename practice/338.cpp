#include <iostream>
#include <vector>

using namespace std;

int countBit(int num)
{
    int count = 0;
    while (num)
    {
        count = count + num % 2;
        num /= 2;
    }
    return count;
}
vector<int> countBits(int n)
{
    vector<int> r;
    for (int i = 0; i <= n; i++)
    {
        r.push_back(countBit(i));
    }
    return r;
}

int main()
{
    vector<int> results;
    results = countBits(2);
    results = countBits(5);
    return 0;
}