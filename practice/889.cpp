#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int i = 0;
        int j = 0;
        return helper(preorder, postorder, i, j);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &postorder, int &i, int &j)
    {
        if (i >= preorder.size())
            return nullptr;
        TreeNode *node = new TreeNode(preorder[i]);

        if (preorder[i] == postorder[j])
        {
            i++;
            j++;
            return node;
        }
        i++;
        node->left = helper(preorder, postorder, i, j);
        if (node->val == postorder[j])
        {
            j++;
            return node;
        }
        node->right = helper(preorder, postorder, i, j);
        if (node->val == postorder[j])
        {
            j++;
        }
        return node;
    }
};

int main()
{
    Solution sln;
    vector<int> preorder;
    vector<int> postorder;

    TreeNode *root;

    // root = sln.constructFromPrePost(preorder = {1, 2, 4, 5, 3, 6, 7}, postorder = {4, 5, 2, 6, 7, 3, 1});
    // root = sln.constructFromPrePost(preorder = {1}, postorder = {1});
    root = sln.constructFromPrePost(preorder = {3, 4, 1, 2}, postorder = {1, 4, 2, 3});
    return 0;
}