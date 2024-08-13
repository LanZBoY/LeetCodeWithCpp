#include <iostream>

using namespace std;

int hammingWeight(int n)
{
    int count = 0;
    while (n)
    {
        count += n % 2;
        n /= 2;
    }
    return count;
}

int main()
{
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(128) << endl;
    cout << hammingWeight(2147483645) << endl;
    for (int i = 1; i <= 256; i++)
    {
        cout << hammingWeight(i) << endl;
    }
}