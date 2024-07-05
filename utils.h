#include <vector>

namespace LeetCode
{

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
        LinkList(std::vector<int>);
        ListNode *getHead()
        {
            return head;
        };

    private:
        ListNode *head;
    };
    LinkList::LinkList(std::vector<int> datas)
    {
        head = new ListNode(datas[0]);
        ListNode *current = head;
        for (int i = 1; i < datas.size(); i++)
        {
            current->next = new ListNode(datas[i]);
            current = current->next;
        }
    }
}