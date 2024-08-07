#include "utils.h"
#include <iostream>
namespace DataStructure
{
    std::string trim(std::string str)
    {
        int i = 0;
        int j = str.size() - 1;
        while (i < j && (str[i] == ' ' || str[j] == ' '))
        {
            if (str[i] == ' ')
                i++;
            if (str[j] == ' ')
                j--;
        }
        return str.substr(i, j - i + 1);
    }
    LinkList::LinkList()
    {
    }

    LinkList::LinkList(std::vector<int> datas)
    {
        if (datas.empty())
        {
            return;
        }
        head = new ListNode(datas[0]);
        tail = head;
        for (int i = 1; i < datas.size(); i++)
        {
            tail->next = new ListNode(datas[i]);
            tail = tail->next;
        }
    }

    void LinkList::addCycle(int position)
    {
        if (position < 0)
            return;
        ListNode *current = head;
        while (current && position--)
            current = current->next;
        tail->next = current;
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

    Tree::Tree(std::string rawStr)
    {
        const std::string NULLFLAG = "null";
        std::queue<TreeNode *> q;
    }

    Graph::Graph(std::vector<std::vector<int>> adjMatrix)
    {
        this->adjMatrix = adjMatrix;
    }

}
