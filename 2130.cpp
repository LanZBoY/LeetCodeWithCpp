#include <iostream>
#include <vector>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

int pairSum(ListNode *head)
{
    if (head->next->next == nullptr)
    {
        return head->val + head->next->val;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *prev = nullptr, *next = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        next = slow->next;
        slow->next = prev;
        prev = slow;

        slow = next;
        fast = fast->next->next;
    }
    next = slow->next;
    slow->next = prev;
    int maxTwinSum = slow->val + next->val;
    while (slow != nullptr && next != nullptr)
    {
        maxTwinSum = max(maxTwinSum, slow->val + next->val);
        slow = slow->next;
        next = next->next;
    }
    return maxTwinSum;
}

int main()
{
    LinkList data = LinkList({5, 4, 2, 1});
    cout << pairSum(data.getHead()) << endl;
    data = LinkList({4, 2, 2, 3});
    cout << pairSum(data.getHead()) << endl;
    data = LinkList({1, 100000});
    cout << pairSum(data.getHead()) << endl;
    return 0;
}