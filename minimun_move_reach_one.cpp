#include <iostream>

using namespace std;

int minMoves(int target, int maxDoubles)
{
    if (maxDoubles == 0)
        return target - 1;
    int n = 0;
    while (target > 1)
    {
        if (target % 2)
        {
            target--;
        }
        else
        {
            if (maxDoubles > 0)
            {
                target /= 2;
                maxDoubles--;
            }
            else
            {
                target--;
            }
        }
        n++;
    }

    return n;
}

int main()
{
    cout << minMoves(5, 0) << endl;
    cout << minMoves(19, 2) << endl;
    cout << minMoves(10, 4) << endl;
    return 0;
}