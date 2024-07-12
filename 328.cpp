#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main()
{
    LinkList data = LinkList({1, 2, 3, 4, 5});
    oddEvenList(data.getHead());
    data = LinkList({2, 1, 3, 5, 6, 4, 7});
    oddEvenList(data.getHead());
    data = LinkList({1, 2, 3, 4, 5, 6, 7, 8});
    oddEvenList(data.getHead());
    data = LinkList({1, 2, 3});
    oddEvenList(data.getHead());
}