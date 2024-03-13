#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
  if (nums.empty()) { return {-1, -1}; }
  int first = findFirst(nums, target);
  int last = findLast(nums, target);
  return {first, last};
}

int findFirst(const std::vector<int>& nums, int target) {
  int idx = -1;
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target == nums[mid]) {
      idx = mid;
      right = mid - 1;
    } else if (target < nums[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return idx;
}

int findLast(const std::vector<int>& nums, int target) {
  int idx = -1;
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target == nums[mid]) {
      idx = mid;
      left = mid + 1;
    } else if (target < nums[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return idx;
}
