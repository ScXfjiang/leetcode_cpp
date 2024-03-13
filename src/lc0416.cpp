#include <vector>
#include <numeric>

// Solution 1 - 2D DP Table (Item First, Capacity Second)
bool canPartition(std::vector<int>& nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0) { return false; }
  int target = sum / 2;
  // dp[i][j] = true if j can be achieved by summing up some of the first i numbers
  std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(target + 1, false));
  // base case: dp[i][0] = true
  for (int i = 0; i <= nums.size(); ++i) { dp[i][0] = true; }
  for (int i = 1; i <= nums.size(); ++i) {
    for (int j = 1; j <= target; ++j) {
      if (j < nums[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[nums.size()][target];
}

// Solution 2 - 2D DP Table (Capacity First, Item Second)
bool canPartition(std::vector<int>& nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0) { return false; }
  int target = sum / 2;
  // dp[i][j] = true if j can be achieved by summing up some of the first i numbers
  std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(target + 1, false));
  // base case: dp[i][0] = true
  for (int i = 0; i <= nums.size(); ++i) { dp[i][0] = true; }
  for (int j = 1; j <= target; ++j) {
    for (int i = 1; i <= nums.size(); ++i) {
      if (j < nums[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[nums.size()][target];
}

// Solution 3 - 1D DP Vector (Item First, Capacity Second)
bool canPartition(std::vector<int>& nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0) { return false; }
  int target = sum / 2;
  // dp[i] = true if i can be achieved by summing up some of the numbers
  std::vector<bool> dp(target + 1, false);
  // base case: dp[0] = true
  dp[0] = true;
  for (int num : nums) {
    for (int i = target; i >= num; --i) {
      if (dp[i - num]) { dp[i] = true; }
    }
  }
  return dp[target];
}
