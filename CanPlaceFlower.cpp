#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n);
};

bool Solution::canPlaceFlowers(vector<int>& flowerbed, int n){
    if(flowerbed.size() == 1){
        if(flowerbed[0]){
            return 0 >= n;
        }
        return 1 >= n;
    }
    for (int i = 0; i < flowerbed.size(); i++){
        if (flowerbed[i] != 1){
            if (i == 0){
                if(flowerbed[i + 1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }else if(i == flowerbed.size() - 1){
                if(flowerbed[i - 1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }else{
                if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        if (n == 0) return true;
    }
    return false;
}

int main(){
    Solution solution;
    vector<int> data = {1, 0, 0, 0, 1};

    solution.canPlaceFlowers(data, 2);
}