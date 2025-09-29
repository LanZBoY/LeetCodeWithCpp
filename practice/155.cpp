#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push({val, val});
            return;
        }
        minStack.push({val, min(val, minStack.top().second)});
    }

    void pop()
    {
        minStack.pop();
    }

    int top()
    {
        return minStack.top().first;
    }

    int getMin()
    {
        return minStack.top().second;
    }
};

int main()
{
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    return 0;
}