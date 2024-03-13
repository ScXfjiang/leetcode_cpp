#include <vector>
#include <algorithm>
#include <limits>

// Solution 1 - Greedy
int maxSubArray(std::vector<int>& nums) {
  int max_sum = std::numeric_limits<int>::min();
  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    max_sum = std::max(max_sum, sum);
    if (sum <= 0) { sum = 0; }
  }
  return max_sum;
}

// Solution 2 - DP
int maxSubArray(std::vector<int>& nums) {
  // dp[i] - maximum sum of subarray in nums[0...i] which must end with nums[i]
  std::vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int max_sum = dp[0];
  for (int i = 1; i < nums.size(); ++i) {
    dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
    max_sum = std::max(max_sum, dp[i]);
  }
  return max_sum;
}
