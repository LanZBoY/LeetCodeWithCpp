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

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    vector<int> max_heap;
    for (int data : arr)
    {
        maxheap_insert(max_heap, data);
    }
    while (!max_heap.empty())
    {
        cout << max_heap[0] << endl;
        pop_root(max_heap);
    }
    return 0;
}