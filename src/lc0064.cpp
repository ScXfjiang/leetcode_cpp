#include <iostream>
#include <vector>

int minPathSum(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  // dp[i][j] = min sum of path from (0, 0) to (i, j)
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        // top-left corner
        dp[i][j] = grid[i][j];
      } else if (i == 0) {
        // first row
        dp[i][j] = dp[i][j - 1] + grid[i][j];
      } else if (j == 0) {
        // first column
        dp[i][j] = dp[i - 1][j] + grid[i][j];
      } else {
        // rest of table
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
  }
  return dp[m - 1][n - 1];
}
