#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    if (rooms.size() == 0)
        return false;
    stack<int> s;
    vector<int> roomsIndex = vector(rooms.size(), 0);
    int visitedRoom = 0;
    s.push(0);
    while (!s.empty())
    {
        int nextRoom = s.top();
        if (roomsIndex[nextRoom] == 0)
        {
            visitedRoom++;
            if (visitedRoom == roomsIndex.size())
                return true;
        }
        if (roomsIndex[nextRoom] >= rooms[nextRoom].size())
        {
            roomsIndex[nextRoom]++;
            s.pop();
            continue;
        }
        s.push(rooms[nextRoom][roomsIndex[nextRoom]++]);
    }
    return visitedRoom == roomsIndex.size();
}
int main()
{
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << canVisitAllRooms(rooms) << endl;
    rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << canVisitAllRooms(rooms) << endl;
    rooms = {{2, 3}, {}, {2}, {1, 3}};
    cout << canVisitAllRooms(rooms) << endl;
    return 0;
}