#include <vector>
#include <limits>

// Solution 1 - Greedy
int maxProfit(std::vector<int>& prices) {
  int max_profit = 0;
  int min_price = std::numeric_limits<int>::max();
  for (int price : prices) {
    // if the current price is less than min_price, update min_price
    if (price < min_price) { min_price = price; }
    // if selling on this day would give us a higher profit than before, update max_profit
    if (price - min_price > max_profit) { max_profit = price - min_price; }
  }
  return max_profit;
}

// Solution 1 - Greedy, Optimized
int maxProfit(std::vector<int>& prices) {
  int max_profit = 0;
  int min_price = std::numeric_limits<int>::max();
  for (int price : prices) {
    if (price < min_price) {
      // if the current price is less than min_price, update min_price
      min_price = price;
    } else if (price - min_price > max_profit) {
      // if selling on this day would give us a higher profit than before, update max_profit
      max_profit = price - min_price;
    }
  }
  return max_profit;
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
    dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
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
    dp[i % 2][1] = std::max(dp[(i - 1) % 2][1], -prices[i]);
  }
  return dp[(n - 1) % 2][0];
}
