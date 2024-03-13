#include <string>

// Solution - Expand Around Center
int countSubstrings(std::string s) {
  int total_count = 0;
  for (int i = 0; i < s.length(); i++) {
    total_count += CountPalindromesAroundCenter(s, i, i);
    total_count += CountPalindromesAroundCenter(s, i, i + 1);
  }
  return total_count;
}

int CountPalindromesAroundCenter(const std::string& s, int left, int right) {
  int count = 0;
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    --left;
    ++right;
    ++count;
  }
  return count;
}
