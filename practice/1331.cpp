#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArray(arr.begin(), arr.end());
        sort(sortedArray.begin(), sortedArray.end());
        int rk = 0;
        unordered_map<int, int> rk_map;
        for (int &num : sortedArray)
        {
            if(rk_map.find(num) == rk_map.end()){
                rk_map[num] = ++rk;
            }
        }
        vector<int> rk_res(arr.size());
        for(int i = 0; i < rk_res.size(); ++i){
            rk_res[i] = rk_map[arr[i]];
        }
        return rk_res;
    }
};

int main()
{

    return 0;
}