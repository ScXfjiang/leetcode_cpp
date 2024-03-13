#include <vector>

int integerBreak(int n) {
  // dp[i] - max product you can get by breaking i into multiple positive integers
  std::vector<int> dp(n + 1, 0);
  // base case: dp[1] = 1
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) { dp[i] = std::max({dp[i], dp[j] * (i - j), j * (i - j)}); }
  }
  return dp[n];
}
