#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool backtracking(vector<vector<char>> &board, string &word, vector<vector<bool>> &used, int checkIdx, int i, int j)
{
    if (checkIdx == word.size() - 1)
    {
        return true;
    }
    used[i][j] = true;
    checkIdx++;
    for (auto [nextI, nextJ] : dirs)
    {
        int x = i + nextI;
        int y = j + nextJ;
        if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && !used[x][y])
        {
            if (word[checkIdx] == board[x][y])
            {
                if (backtracking(board, word, used, checkIdx, x, y))
                {
                    return true;
                }
            }
        }
    }
    used[i][j] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool exist = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            vector<vector<bool>> used(board.size(), vector<bool>(board[i].size(), false));

            if (board[i][j] == word[0])
            {
                if (backtracking(board, word, used, 0, i, j))
                {
                    return true;
                }
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