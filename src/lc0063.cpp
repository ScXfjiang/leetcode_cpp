#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  // dp[i][j] = number of paths from (0, 0) to (i, j)
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (obstacleGrid[i][j] == 1) {
        // obstacle -> no paths to this cell
        dp[i][j] = 0;
      } else if (i == 0 && j == 0) {
        // top-left corner
        dp[i][j] = 1;
      } else if (i == 0) {
        // first row
        dp[i][j] = dp[i][j - 1];
      } else if (j == 0) {
        // first column
        dp[i][j] = dp[i - 1][j];
      } else {
        // rest of table
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  return dp[m - 1][n - 1];
}
