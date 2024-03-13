#include <vector>

// Solution 1 - Binary Search
int search(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) { return mid; }
    if (nums[left] <= nums[mid]) {                       // if left half is sorted
      if (target >= nums[left] && target < nums[mid]) {  // if target is in the left half
        right = mid - 1;
      } else {
        left = mid + 1;  // if target is in the right half
      }
    } else {                                              // otherwise right half is sorted
      if (target > nums[mid] && target <= nums[right]) {  // if target is in the right half
        left = mid + 1;
      } else {
        right = mid - 1;  // if target is in the left half
      }
    }
  }
  return -1;
}

// Solution 2 - Binary Search
int search(std::vector<int>& nums, int target) {
  int n = nums.size();
  // find the the smallest element, which is also the infelction point
  int left = 0;
  int right = n - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= nums[right]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  int rotation = left;
  // binary search for the target
  left = 0;
  right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int real_mid = (mid + rotation) % n;
    if (target == nums[real_mid]) {
      return real_mid;
    } else if (target < nums[real_mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}
