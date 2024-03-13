#include <vector>

int findPeakElement(std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
      // if the mid element is greater than the next one, then a peak must be on the left
      // side, including mid.
      right = mid;
    } else {
      // if the mid element is less than or equal to the next one, then a peak must be on the
      // right side, excluding mid.
      left = mid + 1;
    }
  }
  return left;
}
