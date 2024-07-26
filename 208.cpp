#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Trie
{
public:
    struct Node
    {
        Node() : current(), isWord(false), nextMap(){};
        Node(char c) : current(c), isWord(false), nextMap(){};
        char current;
        bool isWord;
        unordered_map<char, Node *> nextMap;
    };

    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *current = root;
        for (char c : word)
        {
            if (current->nextMap.find(c) == current->nextMap.end())
            {
                current->nextMap[c] = new Node(c);
            }
            current = current->nextMap[c];
        }
        current->isWord = true;
    }

    bool search(string word)
    {
        Node *current = root;
        for (char c : word)
        {
            if (current->nextMap.find(c) == current->nextMap.end())
            {
                return false;
            }
            current = current->nextMap[c];
        }
        return current->isWord;
    }

    bool startsWith(string prefix)
    {
        Node *current = root;
        for (char c : prefix)
        {
            if (current->nextMap.find(c) == current->nextMap.end())
            {
                return false;
            }
            current = current->nextMap[c];
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    t.insert("app");
    cout << t.search("app") << endl;
    cout << t.startsWith("ap") << endl;
    cout << t.startsWith("a") << endl;
}