#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int startPoint = 0;
    int currentHeight = startPoint;
    int maxHeight = currentHeight;
    for (int i = 0; i < gain.size(); i++)
    {
        currentHeight += gain[i];
        maxHeight = max(maxHeight, currentHeight);
    }
    return maxHeight;
}

int main()
{
    vector<int> data = {-5, 1, 5, 0, -7};
    cout << largestAltitude(data) << endl;
    data = {-4, -3, -2, -1, 4, 3, 2};
    cout << largestAltitude(data) << endl;
    return 0;
}