#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "#";
    }
    return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
}

TreeNode *createNode(stringstream &ss)
{
    string nextword;
    ss >> nextword;
    if (nextword == "#")
    {
        return nullptr;
    }

    return new TreeNode(stoi(nextword));
}

TreeNode *helper(stringstream &ss)
{
    TreeNode *root = createNode(ss);
    if (root == nullptr)
        return nullptr;
    root->left = helper(ss);
    root->right = helper(ss);
    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    stringstream ss(data);
    return helper(ss);
}

int main()
{
    Tree t = Tree("[1,2,3,null,null,4,5]");
    string encodeString = serialize(t.getRoot());
    TreeNode *resultRoot = deserialize(encodeString);
    return 0;
}