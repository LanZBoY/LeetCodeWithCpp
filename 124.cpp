#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

int maxPathSum(TreeNode *root, int prevSum, int &currentMax)
{
    if (root == nullptr)
        return prevSum;
    int leftSum = maxPathSum(root->left, 0, currentMax);
    int rightSum = maxPathSum(root->right, 0, currentMax);
    int result = max(root->val, rightSum + root->val);
    result = max(result, leftSum + root->val);

    currentMax = max(currentMax, result);
    currentMax = max(currentMax, leftSum + root->val + rightSum);
    return result;
}

int maxPathSum(TreeNode *root)
{
    int maxResult = INT_MIN;
    int result = maxPathSum(root, 0, maxResult);
    return max(result, maxResult);
}

int main()
{
    Tree t;

    // t = Tree("[2, -1, -2]");
    // cout << maxPathSum(t.getRoot()) << endl;

    t = Tree("[-1,-2,10,-6,null,-3,-6]");
    cout << maxPathSum(t.getRoot()) << endl;

    t = Tree("[-10,9,20,null,null,15,7]");
    cout << maxPathSum(t.getRoot()) << endl;

    t = Tree("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
    cout << maxPathSum(t.getRoot()) << endl;
}