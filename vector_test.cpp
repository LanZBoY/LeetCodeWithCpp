#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a, b;
    a.push_back(1);
    a.push_back(3);
    a.push_back(3);

    b.push_back(1);
    b.push_back(3);
    b.push_back(2);
    cout << (a == b) << endl;
    return 0;
}