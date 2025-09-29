#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int smallest = INT_MAX;
    int smaller = INT_MAX;
    for (int num : nums)
    {
        if (num < smallest)
        {
            smallest = num;
        }
        else if (num < smaller)
        {
            smaller = num;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool increasingTripletV2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> maxRight = vector<int>(n);
    maxRight[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxRight[i] = max(maxRight[i + 1], nums[i + 1]);
    int minLeft = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (minLeft < nums[i] && nums[i] < maxRight[i])
            return true;
        minLeft = min(minLeft, nums[i]);
    }
    return false;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    cout << increasingTripletV2(data) << endl;
    data = {20, 100, 10, 12, 5, 13};
    cout << increasingTripletV2(data) << endl;
    data = {5, 4, 3, 2, 1};
    cout << increasingTripletV2(data) << endl;
    data = {2, 1, 5, 0, 4, 6};
    cout << increasingTripletV2(data) << endl;
    return 0;
}