#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// {0, 1, 2}
// {3, 4, 5}

class Solution
{
private:
    vector<vector<int>> possible_dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

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
        unordered_set<string> visited;
        queue<string> q;
        q.emplace(state);
        int moves = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                state = q.front();
                q.pop();
                if (state == "123450")
                {
                    return moves;
                }
                int currentPos = state.find('0');
                for (int nextPos : possible_dir[currentPos])
                {
                    string nextState = state;
                    swap(nextState[currentPos], nextState[nextPos]);

                    // Skip if this state has been visited
                    if (visited.count(nextState))
                        continue;

                    // Mark the new state as visited and add it to the queue
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
            moves++;
        }
        return -1;
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