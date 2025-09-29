#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0)
            ;
        n--;
        return n <= 0;
    }
    if (flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        flowerbed[0] = 1;
        n--;
    }

    if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0)
    {
        flowerbed[flowerbed.size() - 1] = 1;
        n--;
    }

    for (int i = 1; i < flowerbed.size() - 1; i++)
    {
        if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
        {
            if (flowerbed[i] == 1)
                continue;
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
}

int main()
{
    vector<int> flowerbed;
    int n;

    flowerbed = {1, 0, 0, 0, 1};
    n = 1;
    cout << canPlaceFlowers(flowerbed, n) << endl;

    flowerbed = {1, 0, 0, 0, 1};
    n = 2;
    cout << canPlaceFlowers(flowerbed, n) << endl;

    flowerbed = {1, 0, 1, 0, 1, 0, 1};
    n = 1;
    cout << canPlaceFlowers(flowerbed, n) << endl;

    return 0;
}