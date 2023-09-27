#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

// unsolved
string smallestSubsequence(string s) {
    set <char> duplicate;
    set <char> all_set;
    for (int i = 0; i < s.length(); i++){
        if(all_set.find(s[i]) != all_set.end()){
            duplicate.insert(s[i]);
        }
        all_set.insert(s[i]);
    }

    return "";
}

string decodeAtIndex(string s, int k) {
    queue<string> s_queue;
    queue<int> r_queue;
    for(int i = 0, first = -1; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(first == -1){
                first = i;
            }
        }else{
            if(first != -1){
                s_queue.push(string(s.substr(first, i - first)));
                r_queue.push(s[i] - '0');
                first = -1;
            }
        }
    }
    string result = "";
    while(!s_queue.empty() || !r_queue.empty()){
        int repeat = r_queue.front();
        r_queue.pop();
        result = result + s_queue.front();
        s_queue.pop();
        while(--repeat && result.length() < k){
            result += result;
        }
    }

    return result.substr(k - 1, 1);
}

int main(){
    // smallestSubsequence("bcabc"); // abc
    // smallestSubsequence("cbacdcbc"); // acdb
    cout << decodeAtIndex("leet2code3", 10) << endl;
    return 0;
}