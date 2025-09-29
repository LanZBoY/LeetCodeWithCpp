#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isExit(pair<int, int> &cell, int &step, pair<int, int> &range)
{
    return (cell.first == 0 ||
            cell.first == range.first - 1 ||
            cell.second == 0 ||
            cell.second == range.second - 1) &&
           step != 0;
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    queue<pair<pair<int, int>, int>> qCellStep;
    pair<int, int> range = {maze.size(), maze[0].size()};
    vector<vector<bool>> visited;
    for (int i = 0; i < range.first; i++)
    {
        vector<bool> data(range.second, false);
        visited.push_back(data);
    }
    qCellStep.push({{entrance[0], entrance[1]}, 0});
    visited[entrance[0]][entrance[1]] = true;
    while (!qCellStep.empty())
    {
        pair<int, int> currentCell = qCellStep.front().first;
        int currentStep = qCellStep.front().second;

        if (isExit(currentCell, currentStep, range))
            break;

        if (currentCell.first + 1 < range.first &&
            !visited[currentCell.first + 1][currentCell.second] &&
            maze[currentCell.first + 1][currentCell.second] == '.')
        {
            visited[currentCell.first + 1][currentCell.second] = true;
            qCellStep.push({{currentCell.first + 1, currentCell.second},
                            currentStep + 1});
        }

        if (currentCell.first - 1 >= 0 &&
            !visited[currentCell.first - 1][currentCell.second] &&
            maze[currentCell.first - 1][currentCell.second] == '.')
        {
            visited[currentCell.first - 1][currentCell.second] = true;
            qCellStep.push({{currentCell.first - 1, currentCell.second},
                            currentStep + 1});
        }

        if (currentCell.second + 1 < range.second &&
            !visited[currentCell.first][currentCell.second + 1] &&
            maze[currentCell.first][currentCell.second + 1] == '.')
        {
            visited[currentCell.first][currentCell.second + 1] = true;
            qCellStep.push({{currentCell.first, currentCell.second + 1},
                            currentStep + 1});
        }

        if (currentCell.second - 1 >= 0 &&
            !visited[currentCell.first][currentCell.second - 1] &&
            maze[currentCell.first][currentCell.second - 1] == '.')
        {
            visited[currentCell.first][currentCell.second - 1] = true;
            qCellStep.push({{currentCell.first, currentCell.second - 1},
                            currentStep + 1});
        }
        qCellStep.pop();
    }
    if (qCellStep.empty())
    {
        return -1;
    }
    return qCellStep.front().second;
}

int main()
{
    vector<vector<char>> maze;
    vector<int> entrance;

    maze = {{'+', '+', '.', '+'},
            {'.', '.', '.', '+'},
            {'+', '+', '+', '.'}};
    entrance = {1, 2};
    cout << nearestExit(maze, entrance) << endl;

    maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
    entrance = {1, 0};
    cout << nearestExit(maze, entrance) << endl;

    maze = {{'.', '+'}};
    entrance = {0, 0};
    cout << nearestExit(maze, entrance) << endl;

    maze = {
        {'+', '.', '+', '+', '+', '+', '+'},
        {'+', '.', '+', '.', '.', '.', '+'},
        {'+', '.', '+', '.', '+', '.', '+'},
        {'+', '.', '.', '.', '+', '.', '+'},
        {'+', '+', '+', '+', '+', '.', '+'}};
    entrance = {0, 1};
    cout << nearestExit(maze, entrance) << endl;
    return 0;
}