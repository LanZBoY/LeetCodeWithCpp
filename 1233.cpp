#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    struct Node
    {
        bool isFolder = false;
        unordered_map<string, Node *> next;
    };

    void dfs(pair<string, Node *> root, string current, vector<string> &result)
    {
        current = current + "/" + root.first;
        if (root.second->isFolder)
        {
            result.push_back(current);
            return;
        }
        for (pair<string, Node *> nextPair : root.second->next)
        {
            dfs(nextPair, current, result);
        }
    }

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Node *root = new Node();
        for (string &folderPath : folder)
        {
            stringstream ss(folderPath);
            string token;
            Node *current = root;
            while (getline(ss, token, '/'))
            {
                if (token.empty())
                    continue;
                if (current->next.find(token) == current->next.end())
                    current->next[token] = new Node();
                current = current->next[token];
            }
            current->isFolder = true;
        }
        vector<string> result;
        for (pair<string, Node *> nextPair : root->next)
        {
            dfs(nextPair, "", result);
        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<string> result;
    vector<string> folder;
    result = sln.removeSubfolders(folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"});
    result = sln.removeSubfolders(folder = {"/a", "/a/b/c", "/a/b/d"});
    result = sln.removeSubfolders(folder = {"/a/b/c", "/a/b/ca", "/a/b/d"});
    return 0;
}