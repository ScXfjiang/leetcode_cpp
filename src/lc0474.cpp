#include <vector>
#include <string>

int findMaxForm(std::vector<std::string>& strs, int m, int n) {
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (std::string str : strs) {
    int num_zeros = std::count(str.begin(), str.end(), '0');
    int num_ones = std::count(str.begin(), str.end(), '1');
    for (int i = m; i >= num_zeros; --i) {
      for (int j = n; j >= num_ones; --j) {
        dp[i][j] = std::max(dp[i][j], dp[i - num_zeros][j - num_ones] + 1);
      }
    }
  }
  return dp[m][n];
}
