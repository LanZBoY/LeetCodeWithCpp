#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

class Solution
{
private:
    int dfs(TreeNode *root, int curLevel, int &targetValue)
    {
        if (root == nullptr)
            return curLevel;
        if (targetValue == root->val)
            return curLevel;
        curLevel += 1;
        int maxHeight = dfs(root->left, curLevel, targetValue);
        return max(maxHeight, dfs(root->right, curLevel, targetValue));
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> results(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i)
        {
            results[i] = dfs(root, -1, queries[i]);
        }
        return results;
    }
};

int main()
{
    Solution sln;
    Tree t;
    vector<int> queries;
    vector<int> results;
    t = Tree("[1,3,4,2,null,6,5,null,null,null,null,null,7]");
    results = sln.treeQueries(t.getRoot(), queries = {4});
    t = Tree("[5,8,9,2,1,3,7,4,6]");
    results = sln.treeQueries(t.getRoot(), queries = {3, 2, 4, 8});
    return 0;
}