#include <iostream>
#include <vector>

using namespace std;

bool isRightDirection(int asteroid)
{
    return asteroid > 0;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> remainAsteroids;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (remainAsteroids.empty())
        {
            remainAsteroids.push_back(asteroids[i]);
            continue;
        }
        if (isRightDirection(remainAsteroids.back()) && !isRightDirection(asteroids[i]))
        {
            if (remainAsteroids.back() + asteroids[i] > 0)
                continue;
            if (remainAsteroids.back() + asteroids[i] < 0)
            {
                i--;
            }
            remainAsteroids.pop_back();
        }
        else
        {
            remainAsteroids.push_back(asteroids[i]);
        }
    }
    return remainAsteroids;
}

int main()
{
    vector<int> asteroids = {5, 10, -5};
    asteroidCollision(asteroids);
    asteroids = {8, -8};
    asteroidCollision(asteroids);
    asteroids = {10, 2, -5};
    asteroidCollision(asteroids);
    asteroids = {1, -2, -2, -2};
    asteroidCollision(asteroids);
    return 0;
}