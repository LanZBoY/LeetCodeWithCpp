#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int remove_duplicate_from_sorted_array(vector<int> &nums)
{
    unordered_map<int, int> coutTable;
    int i = 0;
    int removeCount = 0;
    while (i + removeCount < nums.size())
    {
        if (coutTable[nums[i]] < 2)
        {
            coutTable[nums[i]]++;
        }
        else
        {
            for (int j = i; j < nums.size() - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            removeCount++;
            continue;
        }
        i++;
    }
    return i;
}

int main()
{
    vector<int> data = {1, 1, 1, 2, 2, 3};
    cout << remove_duplicate_from_sorted_array(data) << endl;
    data = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << remove_duplicate_from_sorted_array(data) << endl;
    return 0;
}