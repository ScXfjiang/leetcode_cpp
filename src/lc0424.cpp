#include <iostream>
#include <unordered_map>
#include <algorithm>

int characterReplacement(std::string s, int k) {
  std::unordered_map<char, int> char2freq;
  int most_freq = 0;
  int max_len = 0;
  int left = 0;
  for (int right = 0; right < s.size(); ++right) {
    ++char2freq[s[right]];
    most_freq = std::max(most_freq, char2freq[s[right]]);
    if (right - left + 1 - most_freq > k) {
      --char2freq[s[left]];
      ++left;
    }
    max_len = std::max(max_len, right - left + 1);
  }
  return max_len;
}
