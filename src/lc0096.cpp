#include <vector>

// Solution 1 - Recursion
int numTrees(int n) {
  if (n <= 1) { return 1; }
  int cnt = 0;
  for (int i = 0; i < n; ++i) { cnt += numTrees(i) * numTrees(n - (i + 1)); }
  return cnt;
}

// Solution 2 - DP
int numTrees(int n) {
  // dp[i] - number of unique BSTs with i nodes
  std::vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int nodes = 2; nodes <= n; ++nodes) {
    for (int root = 1; root <= nodes; ++root) {
      dp[nodes] += dp[root - 1] * dp[nodes - root];
    }
  }
  return dp[n];
}
