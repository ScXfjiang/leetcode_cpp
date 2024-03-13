#include <string>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstringKDistinct(std::string s, int k) {
  std::unordered_map<char, int> char2cnt;
  int max_len = 0;
  int left = 0;
  for (int right = 0; right < s.size(); ++right) {
    ++char2cnt[s[right]];
    while (char2cnt.size() > k) {
      --char2cnt[s[left]];
      if (char2cnt[s[left]] == 0) { char2cnt.erase(s[left]); }
      ++left;
    }
    max_len = std::max(max_len, right - left + 1);
  }
  return max_len;
}
