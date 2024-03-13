#include <vector>
#include <numeric>

int largestSumAfterKNegations(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] < 0 && k > 0) {
      nums[i] *= -1;
      --k;
    }
  }
  if (k % 2 == 1) { *std::min_element(nums.begin(), nums.end()) *= -1; }
  return std::accumulate(nums.begin(), nums.end(), 0);
}
