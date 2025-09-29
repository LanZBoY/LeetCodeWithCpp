#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

using namespace std;
using namespace DataStructure;

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return (max(maxDepth(root->left) + 1, maxDepth(root->right) + 1));
}

int main()
{
    Tree tree = Tree("[3, 9, 20, null, null, 15, 7]");
    cout << maxDepth(tree.getRoot()) << endl;

    tree = Tree("[1,null,2]");
    cout << maxDepth(tree.getRoot()) << endl;
    return 0;
}