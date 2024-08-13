#include <iostream>
#include <vector>
#include <stack>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> s;
    s.push(root);
    for (int pre = 1, in = 0; pre < preorder.size();)
    {
        while (!s.empty() && s.top()->val != inorder[in])
        {
            TreeNode *newNode = new TreeNode(preorder[pre++]);
            s.top()->left = newNode;
            s.push(newNode);
        }
        TreeNode *temp = nullptr;
        while (!s.empty() && s.top()->val == inorder[in])
        {
            temp = s.top();
            s.pop();
            in++;
        }
        if (pre < preorder.size())
        {
            temp->right = new TreeNode(preorder[pre++]);
            s.push(temp->right);
        }
    }

    return root;
}

int main()
{
    vector<int> preorder, inorder;
    TreeNode *root;

    preorder = {1, 2};
    inorder = {2, 1};
    root = buildTree(preorder, inorder);

    preorder = {1, 2, 4, 6, 5, 3, 7, 8, 9, 10};
    inorder = {4, 2, 5, 6, 1, 3, 8, 9, 7, 10};
    root = buildTree(preorder, inorder);

    preorder = {3, 9, 20, 15, 7};
    inorder = {9, 3, 15, 20, 7};
    root = buildTree(preorder, inorder);

    return 0;
}