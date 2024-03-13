#include <vector>
#include <algorithm>

int maxFrequency(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  long num_op = 0;
  int max_freq = 1;
  int left = 0;
  for (int right = 1; right < nums.size(); ++right) {
    num_op += static_cast<long>(nums[right] - nums[right - 1]) * (right - left);
    while (num_op > k) {
      num_op -= nums[right] - nums[left];
      ++left;
    }
    max_freq = std::max(max_freq, right - left + 1);
  }
  return max_freq;
}
