#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    const int CONVERT = 1000000000;
    int find(int num)
    {
        if (num < 0)
        {
            num = CONVERT - num;
        }
        if (unionFind.find(num) == unionFind.end())
        {
            return INT_MIN;
        }
        if (unionFind[num] < 0)
        {
            return num;
        }
        return unionFind[num] = find(unionFind[num]);
    }

    void insert(int num)
    {
        if (num < 0)
        {
            num = CONVERT - num;
        }
        if (find(num) == INT_MIN)
        {
            unionFind[num] = -1;
        }
    }

    void unionSet(int a, int b)
    {
        int parent_a = find(a);
        int parent_b = find(b);
        if (parent_a == INT_MIN || parent_b == INT_MIN || parent_a == parent_b)
        {
            return;
        }
        if (unionFind[parent_a] > unionFind[parent_b])
        {
            int tmp = parent_a;
            parent_a = parent_b;
            parent_b = tmp;
        }
        unionFind[parent_a] += unionFind[parent_b];
        unionFind[parent_b] = parent_a;
    }

    int longestConsecutive(vector<int> &nums)
    {
        for (int &num : nums)
        {
            insert(num);
            unionSet(num, num + 1);
            unionSet(num, num - 1);
        }
        int maxSize = 0;
        for (pair<int, int> p : unionFind)
        {
            if (p.second > 0)
                continue;
            if (maxSize < -p.second)
            {
                maxSize = -p.second;
            }
        }
        return maxSize;
    }

    void init()
    {
        unionFind.clear();
    }

private:
    unordered_map<int, int> unionFind;
};
int main()
{
    Solution s;
    vector<int> nums;

    s.init();
    nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;

    s.init();
    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << s.longestConsecutive(nums) << endl;

    s.init();
    nums = {1, -8, 7, -2, -4, -4, 6, 3, -4, 0, -7, -1, 5, 1, -9, -3};
    cout << s.longestConsecutive(nums) << endl;

    return 0;
}