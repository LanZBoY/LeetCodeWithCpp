#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "utils.h"

using namespace std;
using namespace DataStructure;

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        queue<TreeNode *> q;
        unordered_map<int, int> level2Sum;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();

            int sum = 0;
            while (size-- > 0)
            {
                TreeNode *current = q.front();
                sum = sum + current->val;
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
                q.pop();
            }
            level2Sum[level++] = sum;
        }

        level = 0;
        q.push(root);
        root->val = level2Sum[level] - root->val;
        while (!q.empty())
        {
            int size = q.size();

            while (size-- > 0)
            {
                TreeNode *current = q.front();
                int sum = 0;
                sum = current->left ? sum + current->left->val : sum;
                sum = current->right ? sum + current->right->val : sum;
                if (sum != 0)
                {
                    int result = level2Sum[level + 1] - sum;
                    if (current->left)
                    {
                        current->left->val = result;
                    }
                    if (current->right)
                    {
                        current->right->val = result;
                    }
                }
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
                q.pop();
            }
            level++;
        }
        return root;
    }
};

int main()
{
    Solution sln;
    Tree t;
    TreeNode *res;

    t = Tree("[5,4,9,1,10,null,7]");
    res = sln.replaceValueInTree(t.getRoot());
    t = Tree("[3,1,2]");
    res = sln.replaceValueInTree(t.getRoot());
    return 0;
}