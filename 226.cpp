#include <iostream>
#include <vector>
#include <queue>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *lefttmp = invertTree(root->left);
    TreeNode *righttmp = invertTree(root->right);
    root->left = righttmp;
    root->right = lefttmp;
    return root;
}

int main()
{
    Tree tree = Tree({4, 2, 7, 1, 3, 6, 9});
    TreeNode *res;

    res = invertTree(tree.getRoot());
    return 0;
}