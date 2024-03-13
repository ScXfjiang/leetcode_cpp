#include <vector>

// Solution 1 - Greedy
int maxProfit(std::vector<int>& prices) {
  int profit = 0;
  for (int i = 0; i < prices.size() - 1; ++i) {
    // if the next day's price is higher than today's, we buy today and sell tomorrow
    if (prices[i + 1] > prices[i]) { profit += prices[i + 1] - prices[i]; }
  }
  return profit;
}

// Solution 2 - DP
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  // dp[i][0] - maximum profit on day i if we don't have a stock
  // dp[i][1] - maximum profit on day i if we have a stock
  std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
  dp[0][1] = -prices[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
  }
  return dp[n - 1][0];
}

// Solution 2 - DP, Optimized
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  std::vector<std::vector<int>> dp(2, std::vector<int>(2, 0));
  dp[0][1] = -prices[0];
  for (int i = 1; i < n; ++i) {
    dp[i % 2][0] = std::max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
    dp[i % 2][1] = std::max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - prices[i]);
  }
  return dp[(n - 1) % 2][0];
}
