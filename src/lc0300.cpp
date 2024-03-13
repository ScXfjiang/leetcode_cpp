#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
  // edge case
  if (nums.empty()) { return 0; }
  // dp[i] = length of LIS ending at nums[i]
  std::vector<int> dp(nums.size(), 1);
  int max_len = 1;
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) { dp[i] = std::max(dp[i], dp[j] + 1); }
    }
    max_len = std::max(max_len, dp[i]);
  }
  return max_len;
}
