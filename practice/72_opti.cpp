#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2)
{
    int dp[word1.size()][word2.size()];
    for (int i = 0; i < word1.size(); i++)
        for (int j = 0; j < word2.size(); j++)
            dp[i][j] = 0;

    return 0;
}

int main()
{
    cout << minDistance("horse", "ros") << endl;
    cout << minDistance("intention", "execution") << endl;
    return 0;
}