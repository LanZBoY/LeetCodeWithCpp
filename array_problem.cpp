#include <iostream>
#include <vector>
using namespace std;



vector<int> encodeInttoArray(int num){
    vector<int> result;
    do{
        int tail = num % 10;
        result.insert(result.begin(), tail);
        num/=10;
    }while (num);
    return result;
}

int decodeArraytoInt(vector<int>& num){
    int result = 0;
    for (int i = 0; i < num.size(); i++){
        result *= 10;
        result += num[i];
    }
    return result;
}

vector<int> addToArrayForm(vector<int>& num, int k){
    vector<int> result;
    vector<int> second_num = encodeInttoArray(k);
    int max_length = max(num.size(), second_num.size());
    while (num.size() < max_length) num.insert(num.begin(), 0);
    while (second_num.size() < max_length) second_num.insert(second_num.begin(), 0);
    int sum = 0;
    int carry = 0;
    for(int i = max_length - 1; i >= 0; i--){
        sum = num[i] + second_num[i] + carry;
        result.insert(result.begin(), sum % 10);
        carry = sum / 10;
    }
    result.insert(result.begin(), carry);
    return result;
}

int main(){
    vector<int> data = {9,9};
    decodeArraytoInt(data);
    vector<int> temp = addToArrayForm(data, 1);
}