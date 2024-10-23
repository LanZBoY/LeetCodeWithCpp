#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

class Solution
{
private:
    void dfs(TreeNode *root, int currentLevel, unordered_map<int, long long> &level2Sum)
    {
        if (root == nullptr)
            return;
        level2Sum[currentLevel] = level2Sum[currentLevel] + root->val;
        dfs(root->left, currentLevel + 1, level2Sum);
        dfs(root->right, currentLevel + 1, level2Sum);
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        unordered_map<int, long long> level2Sum;
        dfs(root, 1, level2Sum);
        if (level2Sum.find(k) == level2Sum.end())
            return -1;
        auto cmp = [](pair<int, long long> &a, pair<int, long long> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
        for (auto levelSumPair : level2Sum)
        {
            pq.push(levelSumPair);
        }
        while (--k > 0)
        {
            pq.pop();
        }

        return pq.top().second;
    }
};

int main()
{
    Tree t;
    Solution sln;
    int k;

    t = Tree("[5,8,9,2,1,3,7,4,6]");
    cout << sln.kthLargestLevelSum(t.getRoot(), 2) << endl;
    t = Tree("[1,2,null,3]");
    cout << sln.kthLargestLevelSum(t.getRoot(), 1) << endl;
    return 0;
}