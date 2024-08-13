#include <iostream>
#include <vector>
#include <queue>
#include "utils.cpp"

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

void mergeKlists(vector<ListNode *> &lists, int i, int j)
{
    if (i == j)
    {
        return;
    }
    int mid = (i + j) / 2;
    mergeKlists(lists, i, mid);
    mergeKlists(lists, mid + 1, j);
    lists[i] = mergeTwoLists(lists[i], lists[mid + 1]);
    lists[mid + 1] = nullptr;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }
    mergeKlists(lists, 0, lists.size() - 1);
    return lists[0];
}

int main()
{
    vector<ListNode *> lists;
    ListNode *res;

    lists = {
        LinkList({1, 4, 5}).getHead(),
        LinkList({1, 3, 4}).getHead(),
        LinkList({2, 6}).getHead(),
    };
    res = mergeKLists(lists);

    lists = {};
    res = mergeKLists(lists);

    lists = {LinkList().getHead()};
    res = mergeKLists(lists);

    return 0;
}