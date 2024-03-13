#include <string>

// Solution 1 - Sort
bool isAnagram(std::string s, std::string t) {
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return s == t;
}

// Solution 2 - Hash Map
bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) { return false; }
  std::unordered_map<char, int> char2count;
  for (char c : s) { ++char2count[c]; }
  for (char c : t) {
    --char2count[c];
    if (char2count[c] < 0) { return false; }
  }
  return true;
}

// Solution 3 - Array
bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) { return false; }
  std::vector<int> freq(256, 0);
  for (char c : s) { ++freq[c]; }
  for (char c : t) {
    --freq[c];
    if (freq[c] < 0) { return false; }
  }
  return true;
}
