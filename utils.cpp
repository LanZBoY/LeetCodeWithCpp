#include "utils.h"
#include <iostream>
namespace DataStructure
{

    LinkList::LinkList(std::vector<int> datas)
    {
        if (datas.empty())
        {
            return;
        }
        head = new ListNode(datas[0]);
        ListNode *current = head;
        for (int i = 1; i < datas.size(); i++)
        {
            current->next = new ListNode(datas[i]);
            current = current->next;
        }
    }

    Tree::Tree(std::vector<int> datas)
    {
        std::queue<TreeNode *> q;
        root = new TreeNode(datas[0]);
        q.push(root);
        for (int i = 1; i < datas.size(); i++)
        {
            int data = datas[i];
            TreeNode *current = q.front();
            TreeNode *newNode = new TreeNode(data);
            if (current->left == nullptr)
            {
                current->left = newNode;
            }
            else if (current->right == nullptr)
            {
                current->right = newNode;
                q.pop();
            }
            if (data != 0)
            {
                q.push(newNode);
            }
        }
    }

    Graph::Graph(std::vector<std::vector<int>> adjMatrix)
    {
        this->adjMatrix = adjMatrix;
    }

}
