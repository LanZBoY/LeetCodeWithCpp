#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

using level2Node = pair<int, TreeNode *>;

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> l;
    if (root == nullptr)
    {
        return l;
    }

    queue<level2Node> q;
    q.push({0, root});

    while (!q.empty())
    {
        if (l.size() == 0 || l.size() - 1 < q.front().first)
        {
            l.push_back({q.front().second->val});
        }
        else
        {
            l[q.front().first].push_back(q.front().second->val);
        }

        if (q.front().second->left != nullptr)
        {
            q.push({q.front().first + 1, q.front().second->left});
        }
        if (q.front().second->right != nullptr)
        {
            q.push({q.front().first + 1, q.front().second->right});
        }
        q.pop();
    }

    return l;
}

int main()
{
    Tree tree = Tree("[3, 9, 20, null, null, 15, 7]");
    vector<vector<int>> results;
    results = levelOrder(tree.getRoot());

    tree = Tree("[1]");
    results = levelOrder(tree.getRoot());

    tree = Tree("[]");
    results = levelOrder(tree.getRoot());

    return 0;
}