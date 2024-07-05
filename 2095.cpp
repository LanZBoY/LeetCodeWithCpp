#include <iostream>
#include <vector>
#include "utils.h"

using namespace LeetCode;
using namespace std;

ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *preSlow = head;
    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    while (fast && fast->next)
    {
        preSlow = preSlow->next;
        slow = slow->next;
        fast = fast->next->next;
    }
    preSlow->next = slow->next;
    return head;
}
int main()
{
    deleteMiddle(LinkList({1, 3, 4, 7, 1, 2, 6}).getHead());
    deleteMiddle(LinkList({1, 2, 3, 4}).getHead());
    deleteMiddle(LinkList({2, 1}).getHead());
    return 0;
}