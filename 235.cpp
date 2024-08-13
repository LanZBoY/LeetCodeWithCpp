#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == p->val || root->val == q->val)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right == nullptr)
    {
        return left;
    }
    else if (left == nullptr && right != nullptr)
    {
        return right;
    }
    else if (right != nullptr && right != nullptr)
    {
        return root;
    }
    return nullptr;
}

int main()
{
    Tree tree;
    TreeNode *p;
    TreeNode *q;
    TreeNode *LCA;
    tree = Tree("[6,2,8,0,4,7,9,null,null,3,5]");
    p = new TreeNode(2);
    q = new TreeNode(8);
    LCA = lowestCommonAncestor(tree.getRoot(), p, q);

    tree = Tree("[6,2,8,0,4,7,9,null,null,3,5]");
    p = new TreeNode(2);
    q = new TreeNode(4);
    LCA = lowestCommonAncestor(tree.getRoot(), p, q);

    tree = Tree("[2, 1]");
    p = new TreeNode(2);
    q = new TreeNode(1);
    LCA = lowestCommonAncestor(tree.getRoot(), p, q);

    return 0;
}