#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> sumMap;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (sumMap.count(num)) {
        int prevIndex = sumMap[num];
        return vector<int>{prevIndex, i};
      }
      sumMap[target - num] = i;
    }

    return vector<int>{-1, -1};
  }
};

int main() {
  vector<int> data;

  vector<int> ans;
  Solution sln;

  ans = sln.twoSum(data = {2, 7, 11, 15}, 9);
  ans = sln.twoSum(data = {3, 2, 4}, 6);
  ans = sln.twoSum(data = {3, 3}, 6);

  return 0;
}