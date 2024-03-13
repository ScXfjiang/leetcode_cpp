#include <vector>
#include <algorithm>

// Solution 1 - 2D DP Table (Item First, Capacity Second)
int coinChange(std::vector<int>& coins, int amount) {
  // dp[i][j] - min number of the first i coins to make up amount j
  std::vector<std::vector<int>> dp(coins.size() + 1,
                                   std::vector<int>(amount + 1, amount + 1));
  // base case: dp[i][0] = 0
  for (int i = 0; i <= coins.size(); ++i) { dp[i][0] = 0; }
  for (int i = 1; i <= coins.size(); ++i) {
    for (int j = 1; j <= amount; ++j) {
      if (j < coins[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
      }
    }
  }
  return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
}

// Solution 2 - 2D DP Table (Capacity First, Item Second)
int coinChange(std::vector<int>& coins, int amount) {
  // dp[i][j] - min number of the first i coins to make up amount j
  std::vector<std::vector<int>> dp(coins.size() + 1,
                                   std::vector<int>(amount + 1, amount + 1));
  // base case: dp[i][0] = 0
  for (int i = 0; i <= coins.size(); ++i) { dp[i][0] = 0; }
  for (int j = 1; j <= amount; ++j) {
    for (int i = 1; i <= coins.size(); ++i) {
      if (j < coins[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
      }
    }
  }
  return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
}

// Solution 3 - 1D DP Vector (Item First, Capacity Second)
int coinChange(std::vector<int>& coins, int amount) {
  // dp[i] = min number of coins to make up amount i
  std::vector<int> dp(amount + 1, amount + 1);
  // base case: dp[0] = 0
  dp[0] = 0;
  for (int coin : coins) {
    for (int i = coin; i <= amount; ++i) { dp[i] = std::min(dp[i], dp[i - coin] + 1); }
  }
  return dp[amount] == amount + 1 ? -1 : dp[amount];
}

// Solution 4 - 1D DP Vector (Capacity First, Item Second)
int coinChange(std::vector<int>& coins, int amount) {
  // dp[i] = min number of coins to make up amount i
  std::vector<int> dp(amount + 1, amount + 1);
  // base case: dp[0] = 0
  dp[0] = 0;
  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i >= coin) { dp[i] = std::min(dp[i], dp[i - coin] + 1); }
    }
  }
  return dp[amount] == amount + 1 ? -1 : dp[amount];
}
