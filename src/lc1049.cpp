#include <vector>
#include <numeric>

// Solution 1 - 2D DP Table (Item First, Capacity Second)
int lastStoneWeightII(std::vector<int>& stones) {
  int sum = std::accumulate(stones.begin(), stones.end(), 0);
  int target = sum / 2;
  // dp[i][j] - the maximum weight using the first i stones with a capacity of j
  std::vector<std::vector<int>> dp(stones.size() + 1, std::vector<int>(target + 1, 0));
  for (int i = 1; i <= stones.size(); ++i) {
    for (int j = 0; j <= target; ++j) {
      if (stones[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
      }
    }
  }
  return sum - 2 * dp[stones.size()][target];
}

// Solution 2 - 2D DP Table (Capacity First, Item Second)
int lastStoneWeightII(std::vector<int>& stones) {
  int sum = std::accumulate(stones.begin(), stones.end(), 0);
  int target = sum / 2;
  // dp[i][j] - the maximum weight using the first i stones with a capacity of j
  std::vector<std::vector<int>> dp(stones.size() + 1, std::vector<int>(target + 1, 0));
  for (int j = 0; j <= target; ++j) {
    for (int i = 1; i <= stones.size(); ++i) {
      if (stones[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
      }
    }
  }
  return sum - 2 * dp[stones.size()][target];
}

// Solution 3 - 1D DP Table (Item First, Capacity Second)
int lastStoneWeightII(std::vector<int>& stones) {
  int sum = std::accumulate(stones.begin(), stones.end(), 0);
  int target = sum / 2;
  // dp[i] - the maximum weight using the first i stones
  std::vector<int> dp(target + 1, 0);
  for (int stone : stones) {
    for (int j = target; j >= stone; --j) { dp[j] = std::max(dp[j], dp[j - stone] + stone); }
  }
  return sum - 2 * dp[target];
}
