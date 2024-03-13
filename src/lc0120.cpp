#include <vector>

// DP: top to [i][j]
int minimumTotal(const std::vector<std::vector<int>>& triangle) {
  // dp[i][j] = min path sum from top to (i, j)
  std::vector<std::vector<int>> dp(triangle);
  for (int i = 1; i < dp.size(); ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      if (j == 0) {
        dp[i][j] += dp[i - 1][j];
      } else if (j == dp[i].size() - 1) {
        dp[i][j] += dp[i - 1][j - 1];
      } else {
        dp[i][j] += std::min(dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
  }
  // optimal value is the minimum of the last row
  int min = dp[dp.size() - 1][0];
  for (int i = 1; i < dp[dp.size() - 1].size(); ++i) {
    if (dp[dp.size() - 1][i] < min) { min = dp[dp.size() - 1][i]; }
  }
  return min;
}

// DP: [i][j] to bottom
int minimumTotal(const std::vector<std::vector<int>>& triangle) {
  // dp[i][j] = min path sum from (i, j) to the bottom
  std::vector<std::vector<int>> dp(triangle);
  for (int i = dp.size() - 2; i >= 0; --i) {
    for (int j = 0; j < dp[i].size(); ++j) { dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]); }
  }
  return dp[0][0];
}
