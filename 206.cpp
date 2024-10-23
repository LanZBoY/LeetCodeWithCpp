#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *pre = nullptr;
    ListNode *current = head;
    while (current)
    {
        ListNode *tmp = current->next;
        current->next = pre;
        pre = current;
        current = tmp;
    }
    return pre;
}

int main()
{
    reverseList(LinkList({1, 2, 3, 4, 5}).getHead());

    reverseList(LinkList({1, 2}).getHead());

    reverseList(LinkList().getHead());
    return 0;
}