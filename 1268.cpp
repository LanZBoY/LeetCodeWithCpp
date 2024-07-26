#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    Node() : current(), isWord(false), nextMap(){};
    Node(char c) : current(c), isWord(false), nextMap(){};
    char current;
    bool isWord;
    unordered_map<char, Node *> nextMap;
};
class Trie
{
public:
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
};

void searchString(Node *current, string startWith, vector<string> &results)
{
    if (results.size() == 3 || current == nullptr)
    {
        return;
    }
    if (current->isWord)
    {
        results.push_back(startWith);
    }
    if (current->nextMap.empty())
    {
        return;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (current->nextMap.find(c) == current->nextMap.end())
            continue;
        Node *next = current->nextMap[c];
        startWith.push_back(next->current);
        searchString(next, startWith, results);
        startWith.pop_back();
        if (results.size() == 3)
            return;
    }
}

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    Trie t;
    for (string product : products)
    {
        t.insert(product);
    }
    vector<vector<string>> resultsList;
    Node *current = t.root;
    string startWith = "";
    for (char c : searchWord)
    {
        vector<string> results;
        startWith.push_back(c);
        if (current)
        {
            current = current->nextMap[c];
        }
        searchString(current, startWith, results);
        resultsList.push_back(results);
    }
    return resultsList;
}

int main()
{
    vector<string> products;
    vector<vector<string>> suggestion;

    products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    suggestion = suggestedProducts(products, "mouse");

    products = {"havana"};
    suggestion = suggestedProducts(products, "havana");

    products = {"baby"};
    suggestion = suggestedProducts(products, "bacb");
}