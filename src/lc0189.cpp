
#include <vector>

void rotate(std::vector<int>& nums, int k) {
  k %= nums.size();
  // reverse the whole array
  std::reverse(nums.begin(), nums.end());
  // reverse the first k elements
  std::reverse(nums.begin(), nums.begin() + k);
  // reverse the rest of the array
  std::reverse(nums.begin() + k, nums.end());
}