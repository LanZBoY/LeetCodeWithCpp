#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> l_r;
    vector<int> r_l;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (l_r.empty() && r_l.empty())
        {
            l_r.push_back(1);
            r_l.push_back(1);
        }
        l_r.push_back(nums[i] * l_r[i]);
        r_l.push_back(nums[nums.size() - 1 - i] * r_l[i]);
    }
    vector<int> result;
    for (int i = 0; i < l_r.size(); i++)
    {
        result.push_back(l_r[i] * r_l[l_r.size() - 1 - i]);
    }
    return result;
}

int main()
{
    vector<int> data = {1, 2, 3, 4};
    productExceptSelf(data);
    data = {-1, 1, 0, -3, 3};
    productExceptSelf(data);
    return 0;
}