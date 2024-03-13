#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Solution 1: DP
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  // dp[i][j] - maximum profit up to day i with transaction action j
  // 0 - initial state
  // 1 - first buy
  // 2 - first sell
  // 3 - second buy
  // 4 - second sell
  std::vector<std::vector<int>> dp(n, std::vector<int>(5, 0));
  dp[0][1] = -prices[0];  // first buy
  dp[0][3] = -prices[0];  // second buy
  for (int i = 1; i < n; ++i) {
    // skip or first buy
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    // skip or first sell
    dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
    // skip or second buy
    dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
    // skip or second sell
    dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
  }
  return dp[n - 1][4];
}

// Solution 1: DP, Optimized
int maxProfit(std::vector<int>& prices) {
  // dp[i] - current maximum profit
  // 0 - initial state
  // 1 - first buy
  // 2 - first sell
  // 3 - second buy
  // 4 - second sell
  std::vector<int> dp(5, 0);
  dp[1] = -prices[0];
  dp[3] = -prices[0];
  for (int i = 1; i < prices.size(); ++i) {
    dp[1] = std::max(dp[1], dp[0] - prices[i]);
    dp[2] = std::max(dp[2], dp[1] + prices[i]);
    dp[3] = std::max(dp[3], dp[2] - prices[i]);
    dp[4] = std::max(dp[4], dp[3] + prices[i]);
  }
  return dp[4];
}

// Solution 2 - Prefix Sum
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  // maximum profit with at most one transaction up to day i
  std::vector<int> first_profit(n, 0);
  int min_price = prices[0];
  for (int i = 1; i < n; ++i) {
    first_profit[i] = std::max(first_profit[i - 1], prices[i] - min_price);
    min_price = std::min(min_price, prices[i]);
  }
  // maximum profit with at most two transactions starting from day i
  std::vector<int> second_profit(n, 0);
  int max_price = prices[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    second_profit[i] = std::max(second_profit[i + 1], max_price - prices[i]);
    max_price = std::max(max_price, prices[i]);
  }
  // calculate the maximum profit
  int max_profit = 0;
  for (int i = 0; i < n; ++i) {
    max_profit = std::max(max_profit, first_profit[i] + second_profit[i]);
  }
  return max_profit;
}
