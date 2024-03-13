#include <iostream>
#include <string>
#include <vector>

bool isInterleave(std::string s1, std::string s2, std::string s3) {
  int m = s1.size();
  int n = s2.size();
  int l = s3.size();
  if (n + m != l) { return false; }
  // dp[i][j] = true if s1.substr(0, i) and s2.substr(0, j) can interleave to s3.substr(0, i + j)
  std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= m; ++i) { dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1]; }
  for (int j = 1; j <= n; ++j) { dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1]; }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                 || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
    }
  }
  return dp[m][n];
}
