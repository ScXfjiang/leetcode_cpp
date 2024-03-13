#include <vector>

// Solution 1 - Recursion
int fib(int n) {
  // base cases
  if (n <= 1) { return n; }
  return fib(n - 1) + fib(n - 2);
}

// Solution 2 - DP with O(n) space
int fib(int n) {
  if (n <= 1) { return n; }
  // dp[i] = fib(i)
  std::vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) { dp[i] = dp[i - 1] + dp[i - 2]; }
  return dp.back();
}

// Solution 3 - Fibonacci Sequence
int fib(int n) {
  if (n <= 1) { return n; }
  int a = 0;
  int b = 1;
  int c = 0;
  for (int i = 2; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}
