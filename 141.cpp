#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

bool hasCycle(ListNode *head)
{
    if (head == nullptr)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main()
{
    LinkList ll;

    ll = LinkList({3, 2, 0, -4});
    ll.addCycle(1);
    cout << hasCycle(ll.getHead()) << endl;

    ll = LinkList({1, 2});
    ll.addCycle(0);
    cout << hasCycle(ll.getHead()) << endl;

    ll = LinkList({1});
    ll.addCycle(-1);
    cout << hasCycle(ll.getHead()) << endl;
    return 0;
}