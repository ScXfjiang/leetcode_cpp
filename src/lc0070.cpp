#include <vector>

// Solution 1: Recursion
int climbStairs(int n) {
  // base cases
  if (n <= 2) { return n; }
  return climbStairs(n - 1) + climbStairs(n - 2);
}

// Solution 2: DP with O(n) space
int climbStairs(int n) {
  // edge cases
  if (n <= 2) { return n; }
  // dp[i] = number of ways to climb to (i+1)th stair
  std::vector<int> dp(n, 0);
  dp[0] = 1;
  dp[1] = 2;
  for (int i = 2; i < n; ++i) { dp[i] = dp[i - 1] + dp[i - 2]; }
  return dp.back();
}

// Solution 3: Fibonacci Sequence 
int climbStairs(int n) {
  if (n <= 2) { return n; }
  int a = 1;
  int b = 2;
  int c = 0;
  for (int i = 3; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}