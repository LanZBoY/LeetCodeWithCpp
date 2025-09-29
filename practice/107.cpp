#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(int cCourse, vector<vector<int>> &inCourses, vector<bool> &visistedSet)
{
    if (visistedSet[cCourse])
    {
        return true;
    }
    visistedSet[cCourse] = true;
    for (int &nCourse : inCourses[cCourse])
    {
        if (dfs(nCourse, inCourses, visistedSet))
        {
            return true;
        }
    }
    visistedSet[cCourse] = false;
    inCourses[cCourse].clear();
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> inCourses(numCourses);
    for (vector<int> &data : prerequisites)
    {
        inCourses[data[0]].push_back(data[1]);
    }
    vector<bool> visistedSet(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (dfs(i, inCourses, visistedSet))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int numCourses;
    vector<vector<int>> prerequisites;

    numCourses = 2;
    prerequisites = {{1, 0}};
    cout << canFinish(numCourses, prerequisites) << endl;

    numCourses = 2;
    prerequisites = {{1, 0}, {0, 1}};
    cout << canFinish(numCourses, prerequisites) << endl;

    numCourses = 5;
    prerequisites = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    cout << canFinish(numCourses, prerequisites) << endl;

    return 0;
}