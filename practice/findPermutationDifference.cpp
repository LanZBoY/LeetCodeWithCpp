#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int findPermutationDifference(string s, string t) {
    char hashArray[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        hashArray[s[i] % 'a'] = i;
    }
    int sum = 0;
    for (int i = 0; i < t.length(); i++) {
        int temp = i - hashArray[t[i] % 'a'];
        if (temp < 0) temp *= -1;
        sum += temp;
    }
    return sum;
}

int findPermutationDifferenceOpt(string s, string t) {
    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        smap[s[i]] = i;
        tmap[t[i]] = i;
    }
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int tmp = smap[s[i]] - tmap[s[i]];
        if (tmp < 0) tmp = -tmp;
        sum += tmp;
    }
    return sum;
}

int main() {
    cout << findPermutationDifferenceOpt("abc", "bac") << endl;
    cout << findPermutationDifferenceOpt("abcde", "edbac") << endl;
}