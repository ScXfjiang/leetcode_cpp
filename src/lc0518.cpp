#include <vector>

// Solution 1 - 2D DP Table (Item First, Capacity Second)
int change(int amount, std::vector<int>& coins) {
  // dp[i][j] - number of combinations to make up amount j using the first i coins
  std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, 0));
  // base case: dp[i][0] = 1
  for (int i = 0; i <= coins.size(); ++i) { dp[i][0] = 1; }
  for (int i = 1; i <= coins.size(); ++i) {
    for (int j = 1; j <= amount; ++j) {
      if (j < coins[i - 1]) {
        // #comb not to use ith coin
        dp[i][j] = dp[i - 1][j];
      } else {
        // #comb not to use ith coin + #comb to use ith coin
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      }
    }
  }
  return dp[coins.size()][amount];
}

// Solution 2 - 2D DP Table (Capacity First, Item Second)
int change(int amount, std::vector<int>& coins) {
  // dp[i][j] - number of combinations to make up amount j using the first i coins
  std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, 0));
  // base case: dp[i][0] = 1
  for (int i = 0; i <= coins.size(); ++i) { dp[i][0] = 1; }
  for (int j = 1; j <= amount; ++j) {
    for (int i = 1; i <= coins.size(); ++i) {
      if (j < coins[i - 1]) {
        // #comb not to use ith coin
        dp[i][j] = dp[i - 1][j];
      } else {
        // #comb not to use ith coin + #comb to use ith coin
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      }
    }
  }
  return dp[coins.size()][amount];
}

// Solution 3 - 1D DP Vector (Item First, Capacity Second)
int change(int amount, std::vector<int>& coins) {
  // dp[i] - number of combinations to make up amount i
  std::vector<int> dp(amount + 1, 0);
  // base case: dp[0] = 1
  dp[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= amount; ++i) { dp[i] += dp[i - coin]; }
  }
  return dp[amount];
}

// Solution 4 - 1D DP Vector (Capacity First, Item Second)
// This Solution is WRONG!!!
int change(int amount, std::vector<int>& coins) {
  // dp[i] - number of combinations to make up amount i
  std::vector<int> dp(amount + 1, 0);
  // base case: dp[0] = 1
  dp[0] = 1;
  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i >= coin) { dp[i] += dp[i - coin]; }
    }
  }
  return dp[amount];
}

// Solution 5 - Backtracking (Time Limit Exceeded)
int change(int amount, std::vector<int>& coins) {
  int num_combs = 0;
  backtracking(amount, coins, 0, num_combs);
  return num_combs;
}

void backtracking(int amount, const std::vector<int>& coins, int start, int& num_combs) {
  if (amount == 0) {
    num_combs++;
    return;
  }
  for (int i = start; i < coins.size(); ++i) {
    if (coins[i] <= amount) { backtracking(amount - coins[i], coins, i, num_combs); }
  }
}
