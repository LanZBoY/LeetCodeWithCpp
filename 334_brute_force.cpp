#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] < nums[j] && nums[j] < nums[k])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    cout << increasingTriplet(data) << endl;
    data = {5, 4, 3, 2, 1};
    cout << increasingTriplet(data) << endl;
    data = {2, 1, 5, 0, 4, 6};
    cout << increasingTriplet(data) << endl;
    return 0;
}