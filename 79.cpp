#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void backtracking(vector<vector<char>> &board, string &word, bool &exist,
                  unordered_set<char *> &checkSet, int checkIdx, int i,
                  int j)
{
    if (exist || checkSet.find(&board[i][j]) != checkSet.end())
        return;
    exist = word.size() - 1 == checkIdx;
    checkIdx++;
    checkSet.insert(&board[i][j]);
    if (!exist && j + 1 < board[i].size() &&
        board[i][j + 1] == word[checkIdx])
    {
        backtracking(board, word, exist, checkSet, checkIdx, i, j + 1);
    }
    if (!exist && i + 1 < board.size() &&
        board[i + 1][j] == word[checkIdx])
    {
        backtracking(board, word, exist, checkSet, checkIdx, i + 1, j);
    }
    if (!exist && j - 1 >= 0 && board[i][j - 1] == word[checkIdx])
    {
        backtracking(board, word, exist, checkSet, checkIdx, i, j - 1);
    }
    if (!exist && i - 1 >= 0 && board[i - 1][j] == word[checkIdx])
    {
        backtracking(board, word, exist, checkSet, checkIdx, i - 1, j);
    }
    checkSet.erase(&board[i][j]);
}

bool exist(vector<vector<char>> &board, string word)
{
    bool exist = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            unordered_set<char *> checkSet;
            if (word[0] == board[i][j])
            {
                backtracking(board, word, exist, checkSet, 0, i, j);
            }
            if (exist)
            {
                return exist;
            }
        }
    }
    return exist;
}

int main()
{
    vector<vector<char>> board;
    board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCB") << endl;

    board = {{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'B', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}};
    cout << exist(board, "AB") << endl;

    board = {{'a', 'b'}, {'c', 'd'}};
    cout << exist(board, "acdb") << endl;
    return 0;
}