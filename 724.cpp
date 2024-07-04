#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    vector<int> leftSum = vector(nums.size() + 1, 0);
    vector<int> rightSum = vector(nums.size() + 1, 0);
    leftSum[1] = nums[0];
    rightSum[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = 1; i < nums.size(); i++)
    {
        leftSum[i + 1] = nums[i] + leftSum[i];
        rightSum[nums.size() - i - 1] = nums[nums.size() - i - 1] + rightSum[nums.size() - i];
    }

    for (int i = 0; i < leftSum.size(); i++)
    {
        if (leftSum[i] == rightSum[i + 1])
            return i;
    }

    return -1;
}

int main()
{
    vector<int> data = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(data) << endl;
    data = {1, 2, 3};
    cout << pivotIndex(data) << endl;
    data = {2, 1, -1};
    cout << pivotIndex(data) << endl;
    return 0;
}