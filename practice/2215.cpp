#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> existSet1(nums1.begin(), nums1.end());
    unordered_set<int> existSet2(nums2.begin(), nums2.end());
    vector<vector<int>> result;
    vector<int> temp1;
    for (int num : existSet1)
    {
        if (existSet2.find(num) == existSet2.end())
            temp1.push_back(num);
    }
    result.push_back(temp1);
    vector<int> temp2;
    for (int num : existSet2)
    {
        if (existSet1.find(num) == existSet1.end())
            temp2.push_back(num);
    }
    result.push_back(temp2);
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    findDifference(nums1, nums2);
    nums1 = {1, 2, 3, 3};
    nums2 = {1, 1, 2, 2};
    findDifference(nums1, nums2);
    return 0;
}