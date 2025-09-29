#include <iostream>
#include <vector>

using namespace std;

int minFlips(int a, int b, int c)
{
    int flipsCount = 0;
    while (a != 0 || b != 0 || c != 0)
    {
        bool bit_a = a % 2;
        bool bit_b = b % 2;
        bool bit_c = c % 2;

        if (bit_c && (!bit_a && !bit_b))
        {
            flipsCount++;
        }
        else if (!bit_c && (bit_a || bit_b))
        {
            flipsCount += bit_a;
            flipsCount += bit_b;
        }

        a /= 2;
        b /= 2;
        c /= 2;
    }
    return flipsCount;
}

int main()
{
    cout << minFlips(2, 6, 5) << endl;
    cout << minFlips(4, 2, 7) << endl;
    cout << minFlips(1, 2, 3) << endl;
    return 0;
}