#include <vector>
#include <algorithm>
#include <limits>

// Solution 1 - DP
int jump(std::vector<int>& nums) {
  int n = nums.size();
  // dp[i] = min #jumps to reach num[i]
  std::vector<int> dp(n, std::numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (j + nums[j] >= i) { dp[i] = std::min(dp[i], dp[j] + 1); }
    }
  }
  return dp.back();
}

// Solution 2 - Greedy
int jump(std::vector<int>& nums) {
  // edge case
  if (nums.size() == 1) { return 0; }
  int num_jumps = 0;
  int cur_reach = 0;
  int next_reach = 0;
  for (int i = 0; i < nums.size(); ++i) {
    next_reach = std::max(next_reach, i + nums[i]);
    // when we reach the end of the current jump range, we need to make another jump
    if (i == cur_reach) {
      ++num_jumps;
      cur_reach = next_reach;
      if (cur_reach >= nums.size() - 1) { break; }
    }
  }
  return num_jumps;
}

// Solution 2 - Greedy, Optimized
int jump(std::vector<int>& nums) {
  // edge case
  if (nums.size() == 1) { return 0; }
  int num_jumps = 0;
  int cur_reach = 0;
  int next_reach = 0;
  for (int i = 0; i < nums.size() - 1; ++i) {
    next_reach = std::max(next_reach, i + nums[i]);
    // when we reach the end of the current jump range, we need to make another jump
    if (i == cur_reach) {
      ++num_jumps;
      cur_reach = next_reach;
    }
  }
  return num_jumps;
}
