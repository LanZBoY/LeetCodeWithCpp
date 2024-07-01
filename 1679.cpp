#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    int count = 0;
    unordered_map<int, int> needToFitNum;
    for (int num : nums)
    {
        if (needToFitNum[num] > 0)
        {
            needToFitNum[num]--;
            count++;
            continue;
        }
        if (num >= k)
            continue;
        needToFitNum[k - num]++;
    }
    return count;
}

int main()
{
    vector<int> data = {2, 5, 4, 4, 1, 3, 4, 4, 1, 4, 4, 1, 2, 1, 2, 2, 3, 2, 4, 2};
    cout << maxOperations(data, 3) << endl;
    data = {3, 1, 3, 4, 3};
    cout << maxOperations(data, 6) << endl;
    return 0;
}