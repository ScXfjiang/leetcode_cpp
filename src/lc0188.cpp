#include <vector>
#include <algorithm>

// Solution - DP
int maxProfit(int k, std::vector<int>& prices) {
  int n = prices.size();
  // dp[i][j] - maximum profit up to day i with transaction action j
  // 0 - initial state
  // j % 2 == 1 - buy
  // j % 2 == 0 - sell
  std::vector<std::vector<int>> dp(n, std::vector<int>(2 * k + 1, 0));
  for (int j = 1; j < 2 * k; j += 2) { dp[0][j] = -prices[0]; }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2 * k - 1; j += 2) {
      // skip or buy
      dp[i][j + 1] = std::max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
      // skip or sell
      dp[i][j + 2] = std::max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
    }
  }
  return dp[n - 1][2 * k];
}

// Solution - DP, Optimized
int maxProfit(int k, std::vector<int>& prices) {
  // dp[i] - current maximum profit
  // 0 - initial state
  // j % 2 == 1 - buy
  // j % 2 == 0 - sell
  std::vector<int> dp(2 * k + 1, 0);
  for (int j = 1; j < 2 * k; j += 2) { dp[j] = -prices[0]; }
  for (int i = 1; i < prices.size(); ++i) {
    for (int j = 1; j < 2 * k; j += 2) {
      dp[j] = std::max(dp[j], dp[j - 1] - prices[i]);
      dp[j + 1] = std::max(dp[j + 1], dp[j] + prices[i]);
    }
  }
  return dp[2 * k];
}
