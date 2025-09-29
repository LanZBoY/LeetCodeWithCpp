#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int> &nums, int target);
        vector<int> twoSumD(vector<int> &nums, int target);
};

vector<int> Solution::twoSum(vector<int> &nums, int target){
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                return vector<int> {nums[i], nums[j]};
            }
        }
    }
    return vector<int> {};
}

vector<int> Solution::twoSumD(vector<int> &nums, int target){
    map<int, int> tempMap;
    for (int i = 0; i < nums.size(); i++){
        map<int, int>::iterator it = tempMap.find(nums[i]);
        if (it != tempMap.end()){
            return vector<int> {it->second, i};
        }
        tempMap[target - nums[i]] = i; 
    }
    return vector<int>{};
}

int main(){
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSumD(nums, target);
}
