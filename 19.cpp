#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *current_n = head;
    while (current_n && n--)
    {
        current_n = current_n->next;
    }
    while (current_n)
    {
        prev = current;
        current = current->next;
        current_n = current_n->next;
    }
    if (prev)
    {
        prev->next = current->next;
    }
    else
    {
        head = current->next;
    }
    delete current;
    return head;
}

int main()
{
    ListNode *res;
    res = removeNthFromEnd(LinkList({1, 2, 3, 4, 5}).getHead(), 2);
    res = removeNthFromEnd(LinkList({1}).getHead(), 1);
    res = removeNthFromEnd(LinkList({1, 2}).getHead(), 1);
    return 0;
}