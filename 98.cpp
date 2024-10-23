#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "utils.h"

using namespace std;
using namespace DataStructure;

void isValidBST(TreeNode *root, long &minValue, bool &isValid)
{
    if (!isValid)
    {
        return;
    }
    if (root == nullptr)
    {
        return;
    }
    isValidBST(root->left, minValue, isValid);
    if (root->val >= minValue)
    {
        minValue = root->val;
    }
    else
    {
        isValid = false;
    }
    isValidBST(root->right, minValue, isValid);
}

bool isValidBST(TreeNode *root)
{
    long minValue = LONG_LONG_MIN;
    bool isValid = true;
    isValidBST(root, minValue, isValid);
    return isValid;
}

int main()
{
    Tree t;
    t = Tree("[5,4,6,null,null,3,7]");
    cout << isValidBST(t.getRoot()) << endl;
    return 0;
}