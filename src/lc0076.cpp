#include <string>
#include <vector>
#include <limits>

std::string minWindow(std::string s, std::string t) {
  if (s.size() < t.size()) { return ""; }
  std::vector<int> char2freq(128, 0);
  for (char c : t) { ++char2freq[c]; }
  int start = 0;
  int len = std::numeric_limits<int>::max();
  int left = 0;
  int right = 0;
  int required = t.size();
  while (right < s.size()) {
    if (char2freq[s[right]] > 0) { --required; }
    --char2freq[s[right]];
    ++right;
    // find a valid window
    while (required == 0) {
      if (right - left < len) {
        start = left;
        len = right - left;
      }
      ++char2freq[s[left]];
      if (char2freq[s[left]] > 0) { required++; }
      left++;
    }
  }
  return len == std::numeric_limits<int>::max() ? "" : s.substr(start, len);
}
