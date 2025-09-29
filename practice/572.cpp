#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr)
        return false;
    if (q == nullptr)
        return false;
    bool result = p->val == q->val;
    result &= isSameTree(p->left, q->left);
    result &= isSameTree(p->right, q->right);
    return result;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr || subRoot == nullptr)
        return false;
    bool result = isSameTree(root, subRoot);
    result |= isSubtree(root->left, subRoot);
    result |= isSubtree(root->right, subRoot);
    return result;
}

int main()
{
    Tree tree;
    Tree subTree;
    tree = Tree("[3,4,5,1,2]");
    subTree = Tree("[4,1,2]");
    cout << isSubtree(tree.getRoot(), subTree.getRoot()) << endl;

    tree = Tree("[3,4,5,1,2,null,null,null,null,0]");
    subTree = Tree("[4,1,2]");
    cout << isSubtree(tree.getRoot(), subTree.getRoot()) << endl;
    return 0;
}