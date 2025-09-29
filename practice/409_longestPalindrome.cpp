#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s)
{
    int sum = 0;
    int maxOdd = 1;
    unordered_map<char, int> counter;
    for (char c : s)
    {
        counter[c]++;
    }
    for (auto data : counter)
    {
        if (data.second % 2 == 1 && data.second > maxOdd)
            maxOdd = data.second;
    }
    for (auto data : counter)
    {
        if (data.second % 2) // odd
        {
            if (data.second == maxOdd)
            {
                sum += data.second;
                maxOdd = -1;
            }
            else
            {
                sum += data.second - 1;
            }
        }
        else // even
        {
            sum += data.second;
        }
    }
    return sum;
}

int main()
{
    cout << longestPalindrome("abccccdd") << endl;
    return 0;
}