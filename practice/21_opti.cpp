#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
    {
        return list2;
    }
    if (list2 == nullptr)
    {
        return list1;
    }
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main()
{
    ListNode *res;
    res = mergeTwoLists(LinkList({1, 2, 4}).getHead(), LinkList({1, 3, 4}).getHead());
    res = mergeTwoLists(LinkList().getHead(), LinkList().getHead());
    res = mergeTwoLists(LinkList().getHead(), LinkList({0}).getHead());

    return 0;
}