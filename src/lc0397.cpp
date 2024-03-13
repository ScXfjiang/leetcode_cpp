#include <vector>

int integerReplacement(int n) {
  std::vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    dp[i] = 1 + (i & 1 == 0 ? dp[i / 2] : std::min(dp[i - 1], 1 + dp[i / 2 + 1]));
  }
  return dp[n];
}