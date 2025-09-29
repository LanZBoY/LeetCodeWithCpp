#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        bool result = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        result = result || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        return result;
    }
};

int main()
{
    Solution sln;
    Tree t1;
    Tree t2;
    t1 = Tree("[1,2,3,4,5,6,null,null,null,7,8]");
    t2 = Tree("[1,3,2,null,6,4,5,null,null,null,null,8,7]");
    cout << sln.flipEquiv(t1.getRoot(), t2.getRoot()) << endl;
    t1 = Tree("[]");
    t2 = Tree("[]");
    cout << sln.flipEquiv(t1.getRoot(), t2.getRoot()) << endl;
    t1 = Tree("[]");
    t2 = Tree("[1]");
    cout << sln.flipEquiv(t1.getRoot(), t2.getRoot()) << endl;
    t1 = Tree("[1,2,3,4,5,6,null,null,null,7,8]");
    t2 = Tree("[1,3,2,null,10,4,5,null,null,null,null,8,7]");
    cout << sln.flipEquiv(t1.getRoot(), t2.getRoot()) << endl;
    return 0;
}