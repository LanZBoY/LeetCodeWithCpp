#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (nums[mid] <= nums[j])
        {
            j = mid;
        }
        else
        {
            i = mid + 1;
        }
    }
    return nums[i];
}

int main()
{
    vector<int> nums;

    nums = {4, 5, 1, 2, 3};
    cout << findMin(nums) << endl;

    nums = {3, 1, 2};
    cout << findMin(nums) << endl;

    nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;

    nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;

    nums = {11, 13, 15, 17};
    cout << findMin(nums) << endl;

    nums = {2, 3, 4, 5, 6, 7, 0, 1};
    cout << findMin(nums) << endl;

    nums = {1, 2, 3, 4, 5, 6, 7, 0};
    cout << findMin(nums) << endl;

    return 0;
}