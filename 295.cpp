#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);
        if (!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        int max_n = maxHeap.size();
        int min_n = minHeap.size();
        while (max_n - min_n > 1 || min_n - max_n > 1)
        {
            if (max_n - min_n > 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (min_n - max_n > 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            max_n = maxHeap.size();
            min_n = minHeap.size();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / (double)2;
        }
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }

private:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main()
{
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    medianFinder->addNum(3);
    medianFinder->addNum(7);
    medianFinder->addNum(4);
    return 0;
}