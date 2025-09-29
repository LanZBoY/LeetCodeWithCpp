#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// {0, 1, 2}
// {3, 4, 5}

class Solution
{
private:
    vector<vector<int>> possible_dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    void dfs(string state, unordered_map<string, int> &visited, int zeroPos, int moves)
    {
        if (visited.count(state) && visited[state] <= moves)
        {
            return;
        }
        visited[state] = moves;
        // start backtracking~
        for (int nextPos : possible_dir[zeroPos])
        {
            swap(state[zeroPos], state[nextPos]);
            dfs(state, visited, nextPos, moves + 1);
            swap(state[zeroPos], state[nextPos]);
        }
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string state = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                state += to_string(board[i][j]);
            }
        }
        unordered_map<string, int> visited;
        dfs(state, visited, state.find('0'), 0);
        return visited.count("123450") ? visited["123450"] : -1;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> board;
    cout << sln.slidingPuzzle(board = {{1, 2, 3}, {4, 0, 5}}) << endl;
    cout << sln.slidingPuzzle(board = {{1, 2, 3}, {5, 0, 4}}) << endl;
    cout << sln.slidingPuzzle(board = {{4, 1, 2}, {5, 0, 3}}) << endl;

    return 0;
}