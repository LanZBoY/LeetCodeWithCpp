#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Trie
{
public:
    Trie()
    {
    }

    void insert(string word)
    {
        Node *current = &root;
        for (char &c : word)
        {
            if (current->links.find(c) == current->links.end())
                current->links[c] = Node();
            current = &current->links[c];
        }
        current->isWord = true;
    }

    bool search(string word)
    {
        Node *current = &root;
        for (char &c : word)
        {
            if (current->links.find(c) == current->links.end())
                return false;
            current = &current->links[c];
        }
        return current->isWord;
    }

    bool startsWith(string prefix)
    {
        Node *current = &root;
        for (char &c : prefix)
        {
            if (current->links.find(c) == current->links.end())
                return false;
            current = &current->links[c];
        }
        return true;
    }

private:
    struct Node
    {
        Node() : isWord(false) {};
        unordered_map<char, Node> links;
        bool isWord;
    };
    Node root;
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