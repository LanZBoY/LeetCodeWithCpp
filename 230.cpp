#include <iostream>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

void solver(TreeNode *root, int &k, int &result)
{
    if (k <= 0 || root == nullptr)
        return;
    solver(root->left, k, result);
    k--;
    if (k == 0)
    {
        result = root->val;
    }
    solver(root->right, k, result);
}

int kthSmallest(TreeNode *root, int k)
{
    int result = 0;
    solver(root, k, result);
    return result;
}

int main()
{
    Tree t = Tree("[3,1,4,null,2]");
    cout << kthSmallest(t.getRoot(), 1) << endl;

    t = Tree("[5,3,6,2,4,null,null,1]");
    cout << kthSmallest(t.getRoot(), 3) << endl;

    return 0;
};