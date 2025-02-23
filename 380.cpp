#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet
{
public:
    unordered_map<int, int> num2index;
    vector<int> nums;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (num2index.find(val) != num2index.end())
        {
            return false;
        }
        int lastIndex = nums.size();
        nums.push_back(val);
        num2index[val] = lastIndex;
        return true;
    }

    bool remove(int val)
    {
        if (num2index.find(val) == num2index.end())
        {
            return false;
        }
        int lastIndex = nums.size() - 1;
        int targetIndex = num2index[val];
        num2index[nums[lastIndex]] = targetIndex;
        num2index.erase(val);

        int temp = nums[lastIndex];
        nums[lastIndex] = nums[targetIndex];
        nums[targetIndex] = temp;
        nums.pop_back();
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

int main()
{
    RandomizedSet rs;
    cout << rs.insert(1) << endl;
    cout << rs.insert(2) << endl;
    cout << rs.insert(2) << endl;
    cout << rs.insert(3) << endl;
    cout << rs.getRandom() << endl;
    cout << rs.getRandom() << endl;
    cout << rs.getRandom() << endl;
    cout << rs.getRandom() << endl;
    cout << rs.remove(2) << endl;
    cout << rs.remove(2) << endl;
    cout << rs.remove(3) << endl;
    cout << rs.remove(1) << endl;
    return 0;
}