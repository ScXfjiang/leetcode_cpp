#include <vector>

// Solution 1 - Binary Search
int findMin(std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= nums[right]) {  // inflection point is on the left half
      right = mid;
    } else {  // infection point is on the right half
      left = mid + 1;
    }
  }
  return nums[left];
}

// Solution 2 - Binary Search
int findMin(std::vector<int>& nums) {
  // edge case 1
  if (nums.size() == 1) { return nums[0]; }
  int left = 0;
  int right = nums.size() - 1;
  // edge case 2: if the array is not rotated (or rotated a complete cycle)
  if (nums[left] < nums[right]) { return nums[left]; }
  // binary search to find the inflection point
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // if mid element is greater than its next element, then mid + 1 element is the minimum
    if (nums[mid] > nums[mid + 1]) { return nums[mid + 1]; }
    // if mid element is less than its previous element, then mid element is the minimum
    if (nums[mid - 1] > nums[mid]) { return nums[mid]; }
    if (nums[mid] <= nums[left]) {  // inflection point is on the left half
      right = mid - 1;
    } else {  // infection point is on the right half
      left = mid + 1;
    }
  }
  return -1;
}
