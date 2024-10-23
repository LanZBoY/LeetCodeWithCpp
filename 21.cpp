#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;
using namespace DataStructure;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr || list2 == nullptr)
    {
        return list1 == nullptr ? list2 : list1;
    }
    ListNode *head = nullptr;
    if (list1->val > list2->val)
    {
        head = list2;
        list2 = list2->next;
    }
    else
    {
        head = list1;
        list1 = list1->next;
    }
    ListNode *current = head;
    while (list1 && list2)
    {
        if (list1->val > list2->val)
        {
            current->next = list2;
            list2 = list2->next;
        }
        else
        {
            current->next = list1;
            list1 = list1->next;
        }
        current = current->next;
    }

    if (list1)
    {
        current->next = list1;
    }
    else
    {
        current->next = list2;
    }

    return head;
}

int main()
{
    ListNode *res;
    vector<int> inputList;
    res = mergeTwoLists(LinkList(inputList = {1, 2, 4}).getHead(), LinkList(inputList = {1, 3, 4}).getHead());
    res = mergeTwoLists(LinkList(inputList = {}).getHead(), LinkList(inputList = {}).getHead());
    res = mergeTwoLists(LinkList(inputList = {}).getHead(), LinkList(inputList = {0}).getHead());

    return 0;
}