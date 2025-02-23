#include <iostream>
#include <string>
#include <stack>
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
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0;
        return helper(traversal, i, 0);
    }

    TreeNode *helper(const string &traversal, int &i, int depth)
    {
        if (i >= traversal.size())
        {
            return nullptr;
        }
        int dashCount = 0;
        while (i < traversal.size() && traversal[i + dashCount] == '-')
        {
            dashCount++;
        }

        if (dashCount != depth)
            return nullptr;

        i += dashCount;

        int value = 0;
        while (i < traversal.size() && isdigit(traversal[i]))
        {
            value = value * 10 + traversal[i] - '0';
            i++;
        }

        TreeNode *node = new TreeNode(value);

        node->left = helper(traversal, i, depth + 1);
        node->right = helper(traversal, i, depth + 1);

        return node;
    }
};

int main()
{
    Solution sln;
    TreeNode *root;
    root = sln.recoverFromPreorder("1-2--3--4-5--6--7");
    root = sln.recoverFromPreorder("1-2--3---4-5--6---7");
    root = sln.recoverFromPreorder("1-401--349---90--88");
    return 0;
}