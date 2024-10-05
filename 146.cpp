#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int data)
    {
        this->key = key;
        this->val = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoubleLinkList
{

private:
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t n_node = 0;

public:
    DoubleLinkList()
    {
    }

    size_t size()
    {
        return n_node;
    }

    Node *front()
    {
        return head;
    }

    Node *back()
    {
        return tail;
    }

    void pop_front()
    {
        Node *node = head;
        if (n_node == 1)
        {
            head = nullptr;
            tail = nullptr;
            n_node--;
            delete node;
            return;
        }
        head = head->next;
        head->prev = nullptr;
        n_node--;
        delete node;
    }

    void push_front(Node *node)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
            n_node++;
            return;
        }
        head->prev = node;
        node->next = head;
        head = node;
        n_node++;
    }

    void push_back(Node *node)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
            n_node++;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
        n_node++;
    }

    void remove(Node *node)
    {
        if (n_node == 1)
        {
            head = nullptr;
            tail = nullptr;
            n_node--;
            return;
        }
        if (node == head)
        {
            head = head->next;
            head->prev = nullptr;
            node->next = nullptr;
            n_node--;
            return;
        }
        if (node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            node->prev = nullptr;
            n_node--;
            return;
        }
        Node *preNode = node->prev;
        Node *nextNode = node->next;
        preNode->next = nextNode;
        nextNode->prev = preNode;
        node->next = nullptr;
        node->prev = nullptr;
        n_node--;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> cache;
    DoubleLinkList dq;
    size_t capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        dq.remove(cache[key]);
        dq.push_back(cache[key]);
        return cache[key]->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            if (dq.size() == this->capacity)
            {
                cache.erase(dq.front()->key);
                dq.pop_front();
            }
            cache[key] = new Node(key, value);
            dq.push_back(cache[key]);
            return;
        }
        Node *tmp = cache[key];
        tmp->val = value;
        dq.remove(tmp);
        dq.push_back(tmp);
    }
};

int main()
{
    LRUCache lru(3);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.put(4, 4);
    cout << lru.get(4) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(1) << endl;
    lru.put(5, 5);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    cout << lru.get(5) << endl;

    return 0;
}