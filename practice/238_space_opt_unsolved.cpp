#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
    }
    return nums;
}

int main()
{
    vector<int> data = {1, 2, 3, 4};
    /*

     */
    productExceptSelf(data);
    data = {-1, 1, 0, -3, 3};
    productExceptSelf(data);
    return 0;
}