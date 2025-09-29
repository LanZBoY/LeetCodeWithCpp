#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

// unsolved
string smallestSubsequence(string s) {
    set<char> duplicate;
    set<char> all_set;
    for (int i = 0; i < s.length(); i++) {
        if (all_set.find(s[i]) != all_set.end()) {
            duplicate.insert(s[i]);
        }
        all_set.insert(s[i]);
    }

    return "";
}

string decodeAtIndex(string s, int k) {
    queue<string> s_queue;
    queue<long> r_queue;
    for (int i = 0, first = -1; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (first == -1) {
                first = i;
            }
        } else {
            if (first != -1) {
                s_queue.push(string(s.substr(first, i - first)));
                r_queue.push(s[i] - '0');
                first = -1;
            } else {
                r_queue.front() = (s[i] - '0') * r_queue.front();
            }
        }
    }
    string result = "";
    while (!s_queue.empty() || !r_queue.empty()) {
        int repeat = r_queue.front();
        r_queue.pop();
        result = result + s_queue.front();
        s_queue.pop();
        while (--repeat && result.length() < k) {
            result += result;
        }
    }

    return result.substr(k - 1, 1);
}

string addBinary(string a, string b) {
    string result = "";
    int max_len = max(a.length(), b.length());
    while (a.length() < max_len) {
        a = "0" + a;
    }
    while (b.length() < max_len) {
        b = "0" + b;
    }
    bool carry_flag = false;
    for (int i = max_len - 1; i >= 0; i--) {
        int a_bin = a[i] - '0';
        int b_bin = b[i] - '0';
        bool current = a_bin ^ b_bin ^ carry_flag;
        carry_flag = ((a_bin & b_bin) | (a_bin & carry_flag) | (b_bin & carry_flag));
        if (current) {
            result = "1" + result;
        } else {
            result = "0" + result;
        }
    }
    if (carry_flag) {
        result = "1" + result;
    }
    return result;
}

int main() {
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
    return 0;
}