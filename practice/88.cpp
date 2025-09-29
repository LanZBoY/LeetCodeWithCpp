#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int current = m + n;
        while (current--)
        {
            if (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[current] = nums1[i--];
                }
                else
                {
                    nums1[current] = nums2[j--];
                }
            }
            else
            {
                if (i >= 0)
                {
                    nums1[current] = nums1[i--];
                }
                else if (j >= 0)
                {
                    nums1[current] = nums2[j--];
                }
            }
        }
    }
};

int main()
{
    vector<int> nums1, nums2;
    int m, n;
    Solution sln;

    sln.merge(nums1 = {1, 2, 3, 0, 0, 0}, m = 3, nums2 = {2, 5, 6}, n = 3);
    return 0;
}