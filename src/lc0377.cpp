#include <vector>

// Solution 1: DP
int combinationSum4(std::vector<int>& nums, int target) {
  // dp[0] - empty combination
  // dp[i] = the number of ways to reach combination of size i
  std::vector<unsigned int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (int num : nums) {
      if (i >= num) { dp[i] += dp[i - num]; }
    }
  }
  return dp.back();
}

// Solution 2: Backtracking (Time Limit Exceededs)
int combinationSum4(std::vector<int>& nums, int target) {
  int count = 0;
  Backtracking(nums, target, count);
  return count;
}

void Backtracking(std::vector<int>& nums, int target, int& count) {
  if (target == 0) {
    count++;
    return;
  }
  for (int num : nums) {
    if (target - num >= 0) { Backtracking(nums, target - num, count); }
  }
}
