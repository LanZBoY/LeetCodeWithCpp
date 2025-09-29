#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool targetFunction(string s) {
    unordered_set<char> vowelSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string a = s.substr(0, s.length() / 2);
    string b = s.substr(s.length() / 2, s.length());
    int vca = 0;

    for (char& c : a) {
        if (vowelSet.find(c) != vowelSet.end()) {
            vca++;
        }
    }
    int vcb = 0;
    for (char& c : b) {
        if (vowelSet.find(c) != vowelSet.end()) {
            vcb++;
        }
    }
    return vca == vcb;
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool optiFunction(string s) {
    int vca = 0;
    int vcb = 0;
    for (int i = 0; i < s.length() / 2; i++) {
        if (isVowel(s[i])) {
            vca++;
        }
        if (isVowel(s[i + s.length() / 2])) {
            vcb++;
        }
    }
    return vca == vcb;
}

int main() {
    cout << targetFunction("book") << endl;
    cout << targetFunction("textbook") << endl;
    cout << targetFunction("MerryChristmas") << endl;
    cout << optiFunction("book") << endl;
    cout << optiFunction("textbook") << endl;
    cout << optiFunction("MerryChristmas") << endl;
    return 0;
}