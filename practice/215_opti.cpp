#include <iostream>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    vector<int> min_heap;
    for (int i = 0; i < k; i++)
    {
        min_heap.push_back(nums[i]);
        int lastIndex = min_heap.size() - 1;
        if (lastIndex == 0)
            continue;
        while (lastIndex > 0)
        {
            int parent = (lastIndex - 1) / 2;
            if (min_heap[parent] > min_heap[lastIndex])
            {
                int tmp = min_heap[parent];
                min_heap[parent] = min_heap[lastIndex];
                min_heap[lastIndex] = tmp;
            }
            lastIndex = parent;
        }
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (min_heap[0] > nums[i])
            continue;
        min_heap[0] = nums[i];
        int current = 0;
        while (current < min_heap.size())
        {
            int smallerIndex = -1;
            if (current * 2 + 1 < min_heap.size() && current * 2 + 2 < min_heap.size())
            {
                smallerIndex = min_heap[current * 2 + 1] < min_heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
            }
            else if (current * 2 + 1 < min_heap.size())
            {
                smallerIndex = current * 2 + 1;
            }
            else if (current * 2 + 2 < min_heap.size())
            {
                smallerIndex = current * 2 + 2;
            }
            else
            {
                break;
            }

            if (min_heap[current] > min_heap[smallerIndex])
            {
                int tmp = min_heap[current];
                min_heap[current] = min_heap[smallerIndex];
                min_heap[smallerIndex] = tmp;
            }
            else
            {
                break;
            }
            current = smallerIndex;
        }
    }
    return min_heap[0];
}

int main()
{
    vector<int> nums;
    int k;
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    cout << findKthLargest(nums, k) << endl;
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}