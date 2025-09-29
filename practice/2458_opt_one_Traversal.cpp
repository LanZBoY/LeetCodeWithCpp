#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils.h"

using namespace std;
using namespace DataStructure;

class Solution
{
private:
    unordered_map<int, int> resultMap;
    unordered_map<TreeNode *, int> heightCache;
    int getSiblingHeight(TreeNode *node, unordered_map<TreeNode *, int> &heightCache)
    {
        if (node == nullptr)
            return -1;

        if (heightCache.count(node))
        {
            return heightCache[node];
        }

        int h = 1 + max(getSiblingHeight(node->left, heightCache),
                        getSiblingHeight(node->right, heightCache));
        heightCache[node] = h;
        return h;
    }
    void dfs(TreeNode *node, int depth, int maxVal,
             unordered_map<int, int> &resultMap,
             unordered_map<TreeNode *, int> &heightCache)
    {
        if (node == nullptr)
            return;

        resultMap[node->val] = maxVal;

        dfs(node->left, depth + 1,
            max(maxVal, depth + 1 + getSiblingHeight(node->right, heightCache)),
            resultMap, heightCache);
        dfs(node->right, depth + 1,
            max(maxVal, depth + 1 + getSiblingHeight(node->left, heightCache)), resultMap,
            heightCache);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        dfs(root, 0, 0, resultMap, heightCache);
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            result[i] = resultMap[queries[i]];
        }
        return result;
    }
};

int main()
{
    Solution sln;
    Tree t;
    vector<int> queries;
    vector<int> results;
    sln = Solution();
    t = Tree("[1,3,4,2,null,6,5,null,null,null,null,null,7]");
    results = sln.treeQueries(t.getRoot(), queries = {4});
    sln = Solution();
    t = Tree("[5,8,9,2,1,3,7,4,6]");
    results = sln.treeQueries(t.getRoot(), queries = {3, 2, 4, 8});
    return 0;
}