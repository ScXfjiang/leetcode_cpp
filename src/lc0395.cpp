#include <string>
#include <unordered_map>

int longestSubstring(std::string s, int k) {
  return LongestSubstrRecursive(s, 0, s.size(), k);
}

int LongestSubstrRecursive(const std::string &s, int start, int end, int k) {
  if (end < k) { return 0; }
  std::unordered_map<char, int> char2cnt;
  for (int i = start; i < end; ++i) { ++char2cnt[s[i]]; }
  for (int i = start; i < end; ++i) {
    if (char2cnt[s[i]] < k) {
      int j = i + 1;
      while (j < end && char2cnt[s[j]] < k) { ++j; }
      return std::max(LongestSubstrRecursive(s, start, i, k),
                      LongestSubstrRecursive(s, j, end, k));
    }
  }
  return end - start;
}
