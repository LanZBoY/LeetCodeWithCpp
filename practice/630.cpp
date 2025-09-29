#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr = to_string(num);
        vector<int> maxRightIndex(numStr.size());
        maxRightIndex[numStr.size() - 1] = numStr.size() - 1;
        for (int i = numStr.size() - 2; i >= 0; --i)
        {
            maxRightIndex[i] = numStr[i] > numStr[maxRightIndex[i + 1]] ? i : maxRightIndex[i + 1];
        }
        for (int i = 0; i < numStr.size(); i++)
        {
            if (numStr[i] < numStr[maxRightIndex[i]])
            {
                swap(numStr[i], numStr[maxRightIndex[i]]);
                return stoi(numStr);
            }
        }
        return num;
    }
};

int main()
{
    Solution sln;
    cout << sln.maximumSwap(22341345) << endl;
    cout << sln.maximumSwap(1234567) << endl;
    cout << sln.maximumSwap(9973) << endl;
    return 0;
}