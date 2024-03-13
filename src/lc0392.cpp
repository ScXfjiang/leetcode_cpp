#include <string>

// Solution 1
bool isSubsequence(std::string s, std::string t) {
  int i = 0;
  int j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) { ++i; }
    ++j;
  }
  return i == s.size();
}

// Solution 2
bool isSubsequence(std::string s, std::string t) {
  int i = 0;
  int j = 0;
  while (i < s.size()) {
    while (j < t.size() && t[j] != s[i]) { ++j; }
    if (j == t.size()) { return false; }
    ++i;
    ++j;
  }
  return true;
}