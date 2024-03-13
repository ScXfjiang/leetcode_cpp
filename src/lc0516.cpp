#include <string>

int longestPalindromeSubseq(std::string s) {
  int n = s.length();
  // dp[i][j] = length of longest palindromic subsequence in s[i...j]
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) { dp[i][i] = 1; }
  for (int len = 2; len <= n; ++len) {
    for (int begin = 0; begin <= n - len; ++begin) {
      int end = begin + len - 1;
      if (s[begin] == s[end]) {
        dp[begin][end] = 2 + (len == 2 ? 0 : dp[begin + 1][end - 1]);
      } else {
        dp[begin][end] = std::max(dp[begin + 1][end], dp[begin][end - 1]);
      }
    }
  }
  return dp[0][n - 1];
}
