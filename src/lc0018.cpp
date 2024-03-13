#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
  std::vector<std::vector<int>> result;
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      long two_sum_target = static_cast<long>(target) - nums[i] - nums[j];
      int left = j + 1;
      int right = nums.size() - 1;
      while (left < right) {
        long two_sum = nums[left] + nums[right];
        if (two_sum < two_sum_target) {
          left++;
        } else if (two_sum > two_sum_target) {
          right--;
        } else {
          std::vector<int> quadruplet(4, 0);
          quadruplet[0] = nums[i];
          quadruplet[1] = nums[j];
          quadruplet[2] = nums[left];
          quadruplet[3] = nums[right];
          result.push_back(quadruplet);
          while (left < right && nums[left] == quadruplet[2]) { ++left; }
          while (left < right && nums[right] == quadruplet[3]) { --right; }
        }
      }
      while (j + 1 < nums.size() && nums[j + 1] == nums[j]) { ++j; }
    }
    while (i + 1 < nums.size() && nums[i + 1] == nums[i]) { ++i; }
  }
  return result;
}
