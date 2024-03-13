#include <vector>
#include <numeric>

int minOperations(std::vector<int>& nums, int x) {
  int target = std::accumulate(nums.begin(), nums.end(), 0) - x;
  if (target < 0) { return -1; }
  int max_len = -1;
  int sum = 0;
  int left = 0;
  for (int right = 0; right < nums.size(); ++right) {
    sum += nums[right];
    while (sum > target) {
      sum -= nums[left];
      ++left;
    }
    if (sum == target) { max_len = std::max(max_len, right - left + 1); }
  }
  return max_len == -1 ? -1 : nums.size() - max_len;
}
