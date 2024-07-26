#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int num = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        num = num ^ nums[i];
    }
    return num;
}

int main()
{
    vector<int> nums;

    nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;

    nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;

    nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;

    return 0;
}