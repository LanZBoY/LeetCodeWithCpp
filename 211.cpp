#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class WordDictionary
{
public:
    WordDictionary()
    {
    }

    void addWord(string word)
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
        return helper(0, &root, word);
    }

private:
    struct Node
    {
        Node() : isWord(false) {};
        unordered_map<char, Node> links;
        bool isWord;
    };
    Node root;

    bool helper(int i, Node *root, string &word)
    {
        if (word.size() == i)
        {
            return root->isWord;
        }
        if (word[i] == '.')
        {
            for (auto [nextC, nextNode] : root->links)
            {
                if (helper(i + 1, &nextNode, word))
                {
                    return true;
                }
            }
        }
        else
        {
            if (root->links.find(word[i]) != root->links.end())
            {
                return helper(i + 1, &root->links[word[i]], word);
            }
        }
        return false;
    }
};

int main()
{
    WordDictionary *wordDict = new WordDictionary();
    wordDict->addWord("bad");
    wordDict->addWord("pad");
    cout << wordDict->search("...") << endl;
    cout << wordDict->search(".ad") << endl;
    cout << wordDict->search("p..") << endl;
    cout << wordDict->search(".a.") << endl;

    wordDict = new WordDictionary();
    wordDict->addWord("a");
    wordDict->addWord("a");
    cout << wordDict->search(".") << endl;
    cout << wordDict->search("a") << endl;
    cout << wordDict->search("aa") << endl;
    cout << wordDict->search("a.") << endl;
    cout << wordDict->search(".a") << endl;
    return 0;
}