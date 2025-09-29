#include <iostream>
#include <vector>

using namespace std;

void maxheap_insert(vector<int> &heap, int insertNum)
{
    heap.push_back(insertNum);
    int i = heap.size() - 1;
    if (i == 0)
        return;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i])
        {
            break;
        }
        int tmp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = tmp;
        i = parent;
    }
}

void pop_root(vector<int> &heap)
{
    int n = heap.size() - 1;

    int tmp = heap[0];
    heap[0] = heap[n];
    heap[n] = tmp;

    heap.pop_back();
    int i = 0;
    while (i < heap.size())
    {
        int leftIndex = i * 2 + 1;
        int rightIndex = i * 2 + 2;
        bool hasLeft = leftIndex < heap.size();
        bool hasRight = rightIndex < heap.size();
        int greaterIndex = -1;
        if (hasLeft && hasRight)
        {
            greaterIndex = heap[leftIndex] > heap[rightIndex] ? leftIndex : rightIndex;
        }
        else if (hasLeft)
        {
            greaterIndex = leftIndex;
        }
        else if (hasRight)
        {
            greaterIndex = rightIndex;
        }
        else
        {
            break;
        }
        if (heap[i] < heap[greaterIndex])
        {
            int tmp = heap[i];
            heap[i] = heap[greaterIndex];
            heap[greaterIndex] = tmp;
        }
        else
        {
            break;
        }
        i = greaterIndex;
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    vector<int> max_heap;
    for (int data : nums)
    {
        maxheap_insert(max_heap, data);
    }
    int result = 0;
    while (!max_heap.empty() && k)
    {
        result = max_heap[0];
        pop_root(max_heap);
        k--;
    }
    return result;
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