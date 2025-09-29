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

void reorderList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *backward = reverseList(slow->next);
    slow->next = nullptr;
    ListNode *forward = head;

    ListNode *current = forward;
    forward = forward->next;
    bool isForward = false;
    while (forward || backward)
    {
        if (isForward && forward)
        {
            current->next = forward;
            forward = forward->next;
        }
        else
        {
            current->next = backward;
            backward = backward->next;
        }
        isForward = !isForward;
        current = current->next;
    }
}

int main()
{
    reorderList(LinkList({1, 2, 3, 4}).getHead());
    reorderList(LinkList({1, 2, 3, 4, 5}).getHead());

    return 0;
}