#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> containSet;

    for (int num : nums) {
      if (containSet.find(num) != containSet.end()) {
        return true;
      }
      containSet.insert(num);
    }

    return false;
  }
};

int main() {
  Solution sln;

  vector<int> data;

  cout << sln.containsDuplicate(data = {1, 2, 3, 3}) << endl;
  cout << sln.containsDuplicate(data = {1, 2, 3}) << endl;
  return 0;
}