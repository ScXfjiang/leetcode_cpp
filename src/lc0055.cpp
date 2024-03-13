#include <vector>
#include <algorithm>

// Solution 1 - Greedy
bool canJump(std::vector<int>& nums) {
  int max_reach = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (max_reach < i) { return false; }
    max_reach = std::max(max_reach, i + nums[i]);
  }
  return true;
}

// Solution 2: DP
bool canJump(std::vector<int>& nums) {
  int n = nums.size();
  // dp[i] = true if there is a path from num[0] to num[i]
  std::vector<bool> dp(n, false);
  dp[0] = true;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] && j + nums[j] >= i) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp.back();
}
