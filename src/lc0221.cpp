#include <vector>
#include <algorithm>

int maximalSquare(std::vector<std::vector<char>>& matrix) {
  if (matrix.empty()) { return 0; }
  int m = matrix.size();
  int n = matrix[0].size();
  // dp[i][j] = side length of largest square with bottom-right corner at (i, j)
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  int max_len = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '1') {
        dp[i][j] = 1;
        if (i > 0 && j > 0) {
          // find the smallest neighbor square to extend
          dp[i][j] += std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
        max_len = std::max(max_len, dp[i][j]);
      }
    }
  }
  return max_len * max_len;
}
