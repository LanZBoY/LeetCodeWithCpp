#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> temp;

        ListNode* current = head;
        while (current != nullptr) {
            if (temp.find(current) != temp.end()) {
                return true;
            }
            temp.insert(current);
            current = current->next;
        }
        return false;
    }
};

ListNode* ConstractList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << endl;
        current = current->next;
    }
}

int main() {
    ListNode* data = ConstractList(vector<int>{3, 2, 0, -4});
    printList(data);
}