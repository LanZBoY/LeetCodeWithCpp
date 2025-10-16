#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> s_map;
    unordered_map<char, int> t_map;
    for (char c : s) {
      s_map[c]++;
    }

    for (char c : t) {
      t_map[c]++;
    }

    for (auto pair : s_map) {
      if (t_map.find(pair.first) == t_map.end() ||
          pair.second != t_map[pair.first]) {
        return false;
      }
    }

    return true;
  }
};
int main() {
  Solution sln;

  cout << sln.isAnagram("anagram", "nagaram") << endl;
  cout << sln.isAnagram("rat", "car") << endl;
  return 0;
}