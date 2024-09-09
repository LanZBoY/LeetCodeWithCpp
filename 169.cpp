#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int halfN = nums.size() / 2;
        unordered_map<int, int> counter;
        int result = 0;
        for (int &num : nums)
        {
            counter[num]++;
            if (counter[num] > halfN)
            {
                result = num;
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    cout << sln.majorityElement(nums = {3, 2, 3}) << endl;
    cout << sln.majorityElement(nums = {2, 2, 1, 1, 1, 2, 2}) << endl;
    return 0;
}