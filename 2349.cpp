#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers
{
private:
    unordered_map<int, int> index2Number;
    unordered_map<int, set<int>> number2Index;

public:
    NumberContainers()
    {
        index2Number = unordered_map<int, int>();
        number2Index = unordered_map<int, set<int>>();
    }

    void change(int index, int number)
    {

        if (index2Number.find(index) != index2Number.end())
        {
            // find the index has been exist
            number2Index[index2Number[index]].erase(index);
        }
        index2Number[index] = number;
        number2Index[number].insert(index);
    }

    int find(int number)
    {
        if (number2Index.find(number) != number2Index.end() && !number2Index[number].empty())
        {
            return *number2Index[number].begin();
        }
        return -1;
    }
};

int main()
{
    NumberContainers nc;
    cout << nc.find(10) << endl;
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    cout << nc.find(10) << endl;
    return 0;
}