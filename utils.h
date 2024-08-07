#include <vector>
#include <queue>

namespace DataStructure
{
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
        Tree(std::vector<int> data);
        Tree(std::string rawStr);
        TreeNode *getRoot()
        {
            return root;
        }

    private:
        TreeNode *root = nullptr;
    };
    class Graph
    {
    public:
        Graph(std::vector<std::vector<int>> adjMatrix);

    private:
        std::vector<std::vector<int>> adjMatrix;
    };
}