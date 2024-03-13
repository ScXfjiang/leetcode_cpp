#include <vector>

int rob(std::vector<int>& nums) {
  if (nums.size() == 1) { return nums[0]; }
  // rob the first house to the second-to-last house
  int rob1 = RobRange(nums, 0, nums.size() - 2);
  // rob the second house to the last house
  int rob2 = RobRange(nums, 1, nums.size() - 1);
  return std::max(rob1, rob2);
}

int RobRange(std::vector<int>& nums, int start, int end) {
  if (end == start) { return nums[start]; }
  std::vector<int> dp(nums.size());
  dp[start] = nums[start];
  dp[start + 1] = std::max(nums[start], nums[start + 1]);
  for (int i = start + 2; i <= end; ++i) {
    dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[end];
}
