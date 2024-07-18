#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int lower = 1;
    int higher = 1000000000;
    while (lower <= higher)
    {
        int mid = (lower + higher) / 2;
        int t_h = 0;
        for (int pile : piles)
        {
            if (mid >= pile)
            {
                t_h++;
            }
            else
            {
                if (pile % mid == 0)
                {
                    t_h = t_h + (pile / mid);
                }
                else
                {
                    t_h = t_h + (pile / mid + 1);
                }
            }
        }
        if (t_h > h)
        {
            lower = mid + 1;
        }
        else if (t_h <= h)
        {
            higher = mid - 1;
        }
    }
    return higher + 1;
}
int main()
{
    vector<int> piles;
    int h;
    piles = {3, 6, 7, 11};
    h = 8;
    cout << minEatingSpeed(piles, h) << endl;

    piles = {30, 11, 23, 4, 20};
    h = 5;
    cout << minEatingSpeed(piles, h) << endl;

    piles = {30, 11, 23, 4, 20};
    h = 6;
    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}