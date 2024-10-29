#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils.h"

using namespace std;
using namespace DataStructure;

class Solution
{
private:
    unordered_map<int, int> maxAfterRemoval;
    int currentMaxHeight = 0;
    void t_left2right(TreeNode *root, int currentLevel)
    {
        if (root == nullptr)
            return;

        maxAfterRemoval[root->val] = currentMaxHeight;

        currentMaxHeight = max(currentLevel, currentMaxHeight);

        t_left2right(root->left, currentLevel + 1);
        t_left2right(root->right, currentLevel + 1);
    }

    void t_right2left(TreeNode *root, int currentLevel)
    {
        if (root == nullptr)
            return;

        maxAfterRemoval[root->val] = max(maxAfterRemoval[root->val], currentMaxHeight);

        currentMaxHeight = max(currentLevel, currentMaxHeight);

        t_right2left(root->right, currentLevel + 1);
        t_right2left(root->left, currentLevel + 1);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> results(queries.size(), 0);
        t_left2right(root, 0);
        currentMaxHeight = 0;
        t_right2left(root, 0);
        for (int i = 0; i < queries.size(); ++i)
        {
            results[i] = maxAfterRemoval[queries[i]];
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