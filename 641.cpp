#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque
{
private:
    vector<int> data;
    int front = 0;
    int last = 0;
    int curr_size = 0;
    int max_size;

public:
    MyCircularDeque(int k)
    {
        data = vector(k, 0);
        max_size = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            data[front] = value;
            curr_size++;
            return true;
        }
        int tmp = (front - 1) % max_size;
        front = tmp >= 0 ? tmp : tmp + max_size;
        data[front] = value;
        curr_size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            data[last] = value;
            curr_size++;
            return true;
        }
        last = (last + 1) % max_size;
        data[last] = value;
        curr_size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % max_size;
        curr_size--;
        if (isEmpty())
        {
            last = 0;
            front = 0;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        int tmp = (last - 1) % max_size;
        last = tmp >= 0 ? tmp : tmp + max_size;
        curr_size--;
        if (isEmpty())
        {
            last = 0;
            front = 0;
        }
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : data[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : data[last];
    }

    bool isEmpty()
    {
        return curr_size == 0;
    }

    bool isFull()
    {
        return curr_size == max_size;
    }
};

int main()
{
    MyCircularDeque deque(3);
    cout << deque.insertLast(5) << endl;
    cout << deque.insertLast(5) << endl;
    cout << deque.insertLast(5) << endl;

    cout << deque.deleteLast() << endl;
    cout << deque.deleteLast() << endl;
    cout << deque.deleteLast() << endl;
    cout << deque.getRear() << endl;

    return 0;
}