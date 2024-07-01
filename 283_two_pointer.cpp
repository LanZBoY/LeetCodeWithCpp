#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    while (j < nums.size() && i < nums.size())
    {
        if (nums[j] == 0)
        {
            j++;
            continue;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        j = i + 1;
        i++;
    }
}

int main()
{
    vector<int> data = {0, 1, 0, 3, 12};
    /*
    {0 1 0 3 12}
    {1 0 0 3 12}
     */
    moveZeroes(data);
    data = {1, 0};
    moveZeroes(data);
    data = {1, 0, 1};
    moveZeroes(data);
    return 0;
}