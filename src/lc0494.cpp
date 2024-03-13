#include <vector>
#include <numeric>

int findTargetSumWays(std::vector<int>& nums, int target) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (std::abs(target) > sum) { return 0; }
  if ((target + sum) % 2 == 1) { return 0; }
  int capacity = (target + sum) / 2;
  std::vector<int> dp(capacity + 1, 0);
  dp[0] = 1;
  for (int num : nums) {
    for (int i = capacity; i >= num; --i) { dp[i] += dp[i - num]; }
  }
  return dp[capacity];
}
