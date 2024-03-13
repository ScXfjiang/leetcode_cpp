#include <vector>
#include <string>

// Solution - Sliding Window
std::vector<int> findAnagrams(std::string s, std::string p) {
  int n = s.size();
  int m = p.size();
  if (n < m) { return {}; }
  std::unordered_map<char, int> char2freq_p;
  std::unordered_map<char, int> char2freq_w;
  std::vector<int> start_indices;
  for (char c : p) { ++char2freq_p[c]; }
  for (int i = 0; i < m; ++i) { ++char2freq_w[s[i]]; }
  for (int i = 0; i <= n - m; ++i) {
    if (i > 0) {
      --char2freq_w[s[i - 1]];
      if (char2freq_w[s[i - 1]] == 0) { char2freq_w.erase(s[i - 1]); }
      ++char2freq_w[s[i + m - 1]];
    }
    if (char2freq_w == char2freq_p) { start_indices.push_back(i); }
  }
  return start_indices;
}

// Solution - Sliding Window, Optimized
std::vector<int> findAnagrams(std::string s, std::string p) {
  int n = s.size();
  int m = p.size();
  if (n < m) { return {}; }
  std::vector<int> char_offset2freq_p(26, 0);
  std::vector<int> char_offset2freq_s(26, 0);
  std::vector<int> start_indices;
  for (char c : p) { ++char_offset2freq_p[c - 'a']; }
  for (int i = 0; i < m; ++i) { ++char_offset2freq_s[s[i] - 'a']; }
  for (int i = 0; i <= n - m; ++i) {
    if (i > 0) {
      --char_offset2freq_s[s[i - 1] - 'a'];
      ++char_offset2freq_s[s[i + m - 1] - 'a'];
    }
    if (char_offset2freq_s == char_offset2freq_p) { start_indices.push_back(i); }
  }
  return start_indices;
}
