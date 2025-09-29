#include <iostream>

using namespace std;

int picked = 1;

int guess(int n)
{
    if (n < picked)
        return 1;
    if (n > picked)
        return -1;
    return 0;
}

int guessNumber(int n)
{
    int lower = 0, higher = n;
    int num = n / 2;
    while (guess(num))
    {
        num = (lower + higher) / 2;
        if (guess(num) > 0)
        {
            lower = num + 1;
        }
        else if (guess(num) < 0)
        {
            higher = num - 1;
        }
    }
    return num;
}

int main()
{
    picked = 1;
    cout << guessNumber(2) << endl;
    picked = 6;
    cout << guessNumber(10) << endl;
    return 0;
}