#include <vector>
#include <limits>

int minSubArrayLen(int target, std::vector<int>& nums) {
  int min_len = std::numeric_limits<int>::max();
  int sum = 0;
  int left = 0;
  for (int right = 0; right < nums.size(); ++right) {
    sum += nums[right];
    while (sum >= target) {
      min_len = std::min(min_len, right - left + 1);
      sum -= nums[left];
      ++left;
    }
  }
  return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
}
