#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) { continue; }
    int target = -nums[i];
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == target) {
        result.push_back({nums[i], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) { ++left; }
        ++left;
        while (left < right && nums[right] == nums[right - 1]) { --right; }
        --right;
      } else if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
  }
  return result;
}
