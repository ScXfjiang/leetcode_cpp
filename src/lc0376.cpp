#include <vector>

// Solution 1
int wiggleMaxLength(std::vector<int>& nums) {
  int n = nums.size();
  if (n < 2) { return n; }
  int prev_diff = nums[1] - nums[0];
  int max_len = prev_diff == 0 ? 1 : 2;
  for (int i = 2; i < n; ++i) {
    int diff = nums[i] - nums[i - 1];
    if ((prev_diff <= 0 && diff > 0) || (prev_diff >= 0 && diff < 0)) {
      ++max_len;
      prev_diff = diff;
    }
  }
  return max_len;
}

// Solution 2
int wiggleMaxLength(std::vector<int>& nums) {
  int n = nums.size();
  if (n < 2) { return n; }
  // length of the longest wiggle subsequences ending with a rising edge
  int up = 1;
  // length of the longest wiggle subsequences ending with a falling edge
  int down = 1;
  for (int i = 1; i < n; ++i) {
    if (nums[i - 1] < nums[i]) {
      // use rising edge to extend a wiggle subsequence ending with a falling edge
      up = down + 1;
    } else if (nums[i - 1] > nums[i]) {
      // use falling edge to extend a wiggle subsequence ending with a rising edge
      down = up + 1;
    }
  }
  return std::max(up, down);
}
