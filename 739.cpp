#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> dms;
    vector<int> results(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!dms.empty() && temperatures[dms.top()] < temperatures[i])
        {
            results[dms.top()] = i - dms.top();
            dms.pop();
        }
        dms.push(i);
    }
    return results;
}

int main()
{
    vector<int> temperatures;
    vector<int> result;
    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    result = dailyTemperatures(temperatures);

    temperatures = {30, 40, 50, 60};
    result = dailyTemperatures(temperatures);

    temperatures = {30, 60, 90};
    result = dailyTemperatures(temperatures);

    return 0;
}