#include <iostream>
#include <vector>
#include <queue>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto swap_condition = [](ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(swap_condition)>
        pq(swap_condition);
    for (ListNode *head : lists)
    {
        if (head != nullptr)
            pq.push(head);
    }
    if (pq.empty())
    {
        return nullptr;
    }
    ListNode *head = pq.top();
    while (!pq.empty())
    {
        ListNode *current = pq.top();
        if (current->next != nullptr)
        {
            pq.push(current->next);
        }
        pq.pop();
        if (!pq.empty())
        {

            current->next = pq.top();
        }
        else
        {
            current->next = nullptr;
        }
    }

    return head;
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