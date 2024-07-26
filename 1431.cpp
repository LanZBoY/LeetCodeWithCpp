#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxNum = candies[0];
    for (int &num : candies)
    {
        maxNum = max(maxNum, num);
        num += extraCandies;
    }
    vector<bool> result(candies.size(), false);
    for (int i = 0; i < candies.size(); i++)
    {
        result[i] = candies[i] >= maxNum ? true : false;
    }
    return result;
}

int main()
{
    vector<int> candies;
    int extraCandies;
    vector<bool> results;

    candies = {2, 3, 5, 1, 3};
    extraCandies = 3;
    results = kidsWithCandies(candies, extraCandies);

    candies = {4, 2, 1, 1, 2};
    extraCandies = 1;
    results = kidsWithCandies(candies, extraCandies);

    candies = {12, 1, 12};
    extraCandies = 10;
    results = kidsWithCandies(candies, extraCandies);

    return 0;
}