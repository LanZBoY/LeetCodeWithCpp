#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int i = 0;
    int N = nums.size();
    int j = N - 1;
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
    if (nums[i] <= target && target <= nums[N - 1])
    {
        j = max(N - 1, 0);
    }
    else
    {
        j = max(i - 1, 0);
        i = 0;
    }

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (target > nums[mid])
        {
            i = mid + 1;
        }
        else if (target < nums[mid])
        {
            j = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums;
    int target;

    nums = {1};
    target = 2;
    cout << search(nums, target) << endl;

    nums = {5, 1, 3};
    target = 5;
    cout << search(nums, target) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << search(nums, target) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 3;
    cout << search(nums, target) << endl;

    nums = {1};
    target = 0;
    cout << search(nums, target) << endl;

    nums = {1, 3};
    target = 1;
    cout << search(nums, target) << endl;

    return 0;
}