#include <iostream>
#include <vector>
using namespace std;

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *current = root;
        for (char &c : word)
        {
            if (current->links[c - 'a'] == nullptr)
            {
                current->links[c - 'a'] = new Node();
            }
            current = current->links[c - 'a'];
        }
        current->isWord = true;
    }

    bool search(string word)
    {
        return helper(0, root, word);
    }

private:
    struct Node
    {
        Node() : isWord(false), links(26, nullptr) {};
        vector<Node *> links;
        bool isWord;
    };
    Node *root;

    bool helper(int i, Node *root, string &word)
    {
        if (word.size() == i)
        {
            return root->isWord;
        }
        if (word[i] == '.')
        {
            for (Node *nextNode : root->links)
            {
                if (nextNode)
                {
                    if (helper(i + 1, nextNode, word))
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            if (root->links[word[i] - 'a'] != nullptr)
            {
                return helper(i + 1, root->links[word[i] - 'a'], word);
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