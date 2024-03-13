#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Solution 1 - Sliding Window + Hash Set
int lengthOfLongestSubstring(std::string s) {
  std::unordered_set<char> seen;
  int max_len = 0;
  int left = 0;
  for (int right = 0; right < s.size(); ++right) {
    char c = s[right];
    while (seen.find(c) != seen.end()) { seen.erase(s[left++]); }
    seen.insert(c);
    max_len = std::max(max_len, right - left + 1);
  }
  return max_len;
}

// Solution 2 - Sliding Window + Hash Map
int lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, int> char2latest_idx;
  int max_len = 0;
  int left = 0;
  for (int right = 0; right < s.size(); ++right) {
    char c = s[right];
    if (char2latest_idx.find(c) != char2latest_idx.end() && char2latest_idx[c] >= left) {
      left = char2latest_idx[c] + 1;
    }
    char2latest_idx[c] = right;
    max_len = std::max(max_len, right - left + 1);
  }
  return max_len;
}
