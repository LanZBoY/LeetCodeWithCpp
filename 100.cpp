#include <iostream>
#include <vector>
#include <queue>
#include "utils.cpp"

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

int main()
{
    Tree t1, t2;
    t1 = Tree("[1, 2, 3]");
    t2 = Tree("[1, 2, 3]");
    cout << isSameTree(t1.getRoot(), t2.getRoot()) << endl;
    return 0;
}