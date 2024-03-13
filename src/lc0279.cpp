#include <vector>
#include <limits.h>

// Solution 1 - 1D DP Vector (Item First, Capacity Second)
int numSquares(int n) {
  std::vector<int> squares;
  for (int i = 1; i * i <= n; ++i) { squares.push_back(i * i); }
  // dp[i] - min number of perfect square numbers which sum to i
  std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
  // base case: dp[0] = 0
  dp[0] = 0;
  for (int s : squares) {
    for (int i = s; i <= n; ++i) { dp[i] = std::min(dp[i], dp[i - s] + 1); }
  }
  return dp[n];
}

// Solution 2 - 1D DP Vector (Capacity First, Item Second)
int numSquares(int n) {
  std::vector<int> squares;
  for (int i = 1; i * i <= n; ++i) { squares.push_back(i * i); }
  // dp[i] - min number of perfect square numbers which sum to i
  std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
  // base case: dp[0] = 0
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int s : squares) {
      if (i >= s) { dp[i] = std::min(dp[i], dp[i - s] + 1); }
    }
  }
  return dp[n];
}
