#include <vector>
#include <queue>

namespace DataStructure
{

    std::string trim(std::string str)
    {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
    // LinkList by WenTee
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class LinkList
    {
    public:
        LinkList();
        LinkList(std::vector<int>);
        ListNode *getHead()
        {
            return head;
        };

        void addCycle(int position);

    private:
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
    };

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

    // Binary Tree by WenTee
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Tree
    {
    public:
        Tree();
        Tree(TreeNode *);
        Tree(std::vector<int>);
        Tree(std::string);
        TreeNode *getRoot()
        {
            return root;
        }

    private:
        TreeNode *root = nullptr;
    };

    Tree::Tree()
    {
    }
    Tree::Tree(TreeNode *root)
    {
        this->root = root;
    }
    // 完全展開樹使用
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
        }
    }
    // 非完全展開樹時使用
    Tree::Tree(std::string rawStr)
    {
        const std::string NULLFLAG = "null";
        std::queue<TreeNode *> q;
        int i = 0;
        int j = 0;
        bool addLeft = true;
        for (char &c : rawStr)
        {
            if (c == ']' || c == ',')
            {
                std::string tmp = trim(rawStr.substr(i + 1, j - i - 1));
                if (tmp.empty())
                {
                    j++;
                    continue;
                }
                TreeNode *current = nullptr;
                if (NULLFLAG != tmp)
                {
                    int data = stoi(tmp);
                    current = new TreeNode(data);
                }
                if (current != nullptr)
                {
                    q.push(current);
                }
                if (root != nullptr)
                {
                    if (addLeft)
                    {
                        q.front()->left = current;
                    }
                    else
                    {
                        q.front()->right = current;
                        q.pop();
                    }
                    addLeft = !addLeft;
                }
                else
                {
                    root = current;
                }
            }
            if (c == '[' || c == ',')
            {
                i = j;
            }
            j++;
        }
    }
    class Graph
    {
    public:
        Graph(std::vector<std::vector<int>> adjMatrix);

    private:
        std::vector<std::vector<int>> adjMatrix;
    };

    Graph::Graph(std::vector<std::vector<int>> adjMatrix)
    {
        this->adjMatrix = adjMatrix;
    }
}