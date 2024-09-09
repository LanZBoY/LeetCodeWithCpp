#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node
{
    Node() : isWord(false) {};
    unordered_map<char, Node *> links;
    bool isWord;
};

void addWord(Node *root, string word)
{
    Node *current = root;
    for (char &c : word)
    {
        if (current->links[c] == nullptr)
        {
            current->links[c] = new Node();
        }
        current = current->links[c];
    }
    current->isWord = true;
}

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void backtracking(unordered_set<string> &result, vector<vector<char>> &board, vector<vector<bool>> &used, string &targetWord, int i, int j, Node *currentNode)
{
    if (currentNode->isWord)
    {
        result.insert(targetWord);
    }

    for (auto [x, y] : dirs)
    {
        int nextI = x + i;
        int nextJ = y + j;
        if (nextI >= 0 && nextI < board.size() && nextJ >= 0 && nextJ < board[nextI].size() && !used[nextI][nextJ])
        {
            if (currentNode->links[board[nextI][nextJ]] != nullptr)
            {
                used[nextI][nextJ] = true;
                targetWord.push_back(board[nextI][nextJ]);
                Node *nextNode = currentNode->links[board[nextI][nextJ]];
                backtracking(result, board, used, targetWord, nextI, nextJ, nextNode);
                targetWord.pop_back();
                used[nextI][nextJ] = false;
            }
        }
    }
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    unordered_set<string> results;
    int M = board.size();
    int N = board[0].size();
    Node *root = new Node();
    for (string &word : words)
    {
        addWord(root, word);
    }

    vector<vector<bool>> used = vector(M, vector(N, false));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (root->links[board[i][j]] != nullptr)
            {
                string targetWord = "";
                used[i][j] = true;
                targetWord.push_back(board[i][j]);
                Node *nextNode = root->links[board[i][j]];
                backtracking(results, board, used, targetWord, i, j, nextNode);
                targetWord.pop_back();
                used[i][j] = false;
            }
        }
    }
    return vector(results.begin(), results.end());
}

int main()
{
    vector<vector<char>> board;
    vector<string> words;
    vector<string> results;

    board = {{'o', 'a', 'a', 'n'},
             {'e', 't', 'a', 'e'},
             {'i', 'h', 'k', 'r'},
             {'i', 'f', 'l', 'v'}};
    words = {"oath", "pea", "eat", "rain"};
    results = findWords(board, words);

    board = {{'a', 'b'},
             {'c', 'd'}};
    words = {"abcb"};
    results = findWords(board, words);

    return 0;
}