#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            for (int j = i; j < nums.size() - 1; j++)
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> data = {0, 1, 0, 3, 12};
    moveZeroes(data);
    return 0;
}