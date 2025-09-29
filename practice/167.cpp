#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            int tmpSum = numbers[i] + numbers[j];
            if (tmpSum > target)
            {
                j--;
            }
            else if (tmpSum < target)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        return {i + 1, j + 1};
    }
};

int main()
{
    Solution sln;
    vector<int> numbers, results;
    int target;

    results = sln.twoSum(numbers = {2, 7, 11, 15}, target = 9);
    results = sln.twoSum(numbers = {2, 3, 4}, target = 6);
    results = sln.twoSum(numbers = {-1, 0}, target = -1);
    return 0;
}