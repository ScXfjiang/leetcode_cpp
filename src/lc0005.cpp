#include <iostream>
#include <string>
#include <vector>

// Solution 1 - Expand around center
std::string longestPalindrome(std::string s) {
  int begin = 0;
  int max_len = 1;
  for (int i = 0; i < s.size(); i++) {
    int odd_len = LengthOfLongestPalindromAroundCenter(s, i, i);
    int even_len = LengthOfLongestPalindromAroundCenter(s, i, i + 1);
    int len = std::max(odd_len, even_len);
    if (len > max_len) {
      begin = i - (len - 1) / 2;
      max_len = len;
    }
  }
  return s.substr(begin, max_len);
}

int LengthOfLongestPalindromAroundCenter(const std::string& s, int left, int right) {
  while (left >= 0 && right < s.size() && s[left] == s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}

// Solution 2: DP
std::string longestPalindrome(std::string s) {
  int n = s.size();
  // edge case
  if (n <= 1) { return s; }
  // dp[i][j] = true if s[i...j] is a palindrome
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
  int begin = 0;
  int max_len = 1;
  // substrings of length 1
  for (int i = 0; i < n; ++i) { dp[i][i] = true; }
  // substrings of length 2
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      begin = i;
      max_len = 2;
    }
  }
  // substrings of length > 2
  for (int len = 3; len <= n; ++len) {
    for (int i = 0; i < n - len + 1; ++i) {
      int j = i + len - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        begin = i;
        max_len = len;
      }
    }
  }
  return s.substr(begin, max_len);
}
