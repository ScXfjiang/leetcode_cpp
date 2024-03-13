#include <vector>
#include <limits>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  // make sure nums1 is the smaller array
  if (nums1.size() > nums2.size()) { return findMedianSortedArrays(nums2, nums1); }
  int m = nums1.size();
  int n = nums2.size();
  int left = 0;
  int right = m;
  while (left <= right) {
    int partition_x = (left + right) / 2;
    int partition_y = (m + n + 1) / 2 - partition_x;
    // if partition_x is 0 it means nothing is there on left side
    int max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
    // if partition_x is the length of input then there is nothing on right side
    int min_right_x = (partition_x == m) ? INT_MAX : nums1[partition_x];
    // if partition_y is 0 it means nothing is there on left side
    int max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];
    // if partition_y is the length of input then there is nothing on right side
    int min_right_y = (partition_y == n) ? INT_MAX : nums2[partition_y];
    if (max_left_x <= min_right_y
        && max_left_y <= min_right_x) {  // we have partitioned array at correct place
      if ((m + n) % 2 == 0) {
        return (std::max(max_left_x, max_left_y) + std::min(min_right_x, min_right_y)) / 2.0;
      } else {
        return std::max(max_left_x, max_left_y);
      }
    } else if (max_left_x > min_right_y) {  // we are too far on right side for partition_x
      right = partition_x - 1;
    } else {  // we are too far on left side for partition_x
      left = partition_x + 1;
    }
  }
  // if we reach here, then the arrays are not sorted properly
  throw std::invalid_argument("Input arrays are not sorted or not the right inputs.");
}
