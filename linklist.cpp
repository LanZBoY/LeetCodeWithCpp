#include <iostream>

using namespace std;

struct node {
    int value;
    node *next = nullptr;
    node(int data) : value(data), next(nullptr){};
};

struct LinkList {
    node *head = nullptr;
    node *tail = nullptr;
    LinkList() : head(NULL), tail(NULL) {}
};

void appendNode(LinkList *list, int data) {
    if (list->head == nullptr) {
        list->head = new node(data);
        list->tail = list->head;
        return;
    }
    list->tail->next = new node(data);
    list->tail = list->tail->next;
}

void printLinkList(LinkList *ll) {
    node *current = ll->head;
    while (current != nullptr) {
        cout << current->value << ", ";
        current = current->next;
    }
}

int main() {
    LinkList *ll = new LinkList();
    appendNode(ll, 10);
    appendNode(ll, 12);
    appendNode(ll, 20);
    printLinkList(ll);
    cout << "OK" << endl;
}
