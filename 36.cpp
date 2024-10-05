#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check row
        for (vector<char> &row : board)
        {
            unordered_set<char> cotainNum;
            for (char &c : row)
            {
                if (c == '.')
                    continue;
                if (cotainNum.find(c) == cotainNum.end())
                {
                    cotainNum.insert(c);
                }
                else
                {
                    return false;
                }
            }
        }
        // check col
        for (int i = 0; i < 9; ++i)
        {
            unordered_set<char> cotainNum;
            for (int j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.')
                    continue;
                if (cotainNum.find(board[j][i]) == cotainNum.end())
                {
                    cotainNum.insert(board[j][i]);
                }
                else
                {
                    return false;
                }
            }
        }
        // check range
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                unordered_set<char> cotainNum;
                int r_offset = i * 3;
                int c_offset = j * 3;
                for (int r = r_offset; r < r_offset + 3; ++r)
                {
                    for (int c = c_offset; c < c_offset + 3; ++c)
                    {
                        if (board[r][c] == '.')
                            continue;
                        if (cotainNum.find(board[r][c]) == cotainNum.end())
                        {
                            cotainNum.insert(board[r][c]);
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sln;

    vector<vector<char>> board;

    cout << sln.isValidSudoku(
                board = {
                    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}})
         << "\n";

    cout << sln.isValidSudoku(
                board = {
                    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}})
         << "\n";

    return 0;
}