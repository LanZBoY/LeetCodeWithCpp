#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> rotatedTheBox(n, vector<char>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotatedTheBox[i][j] = box[m - 1 - j][i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            int downPostion = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (rotatedTheBox[j][i] == '#')
                {
                    int tmp = rotatedTheBox[downPostion][i];
                    rotatedTheBox[downPostion][i] = rotatedTheBox[j][i];
                    rotatedTheBox[j][i] = tmp;
                    downPostion--;
                }
                else if (rotatedTheBox[j][i] == '*')
                {
                    downPostion = j - 1;
                }
            }
        }
        return rotatedTheBox;
    }
};

int main()
{
    Solution sln;
    vector<vector<char>> box;
    vector<vector<char>> result;
    result = sln.rotateTheBox(box = {{'#', '.', '#'}});
    result = sln.rotateTheBox(box = {
                                  {'#', '.', '*', '.'},
                                  {'#', '#', '*', '.'},
                              });
    return 0;
}