#include <vector>
#include <algorithm>

// Solution 1
int removeElement(std::vector<int>& nums, int val) {
  return std::remove(nums.begin(), nums.end(), val) - nums.begin();
}

// Solution 2
int removeElement(std::vector<int>& nums, int val) {
  int i = 0;  // pass-the-end idx of the reserved part
  for (int j = 0; j < nums.size(); ++j) {
    if (nums[j] != val) { nums[i++] = nums[j]; }
  }
  return i;
}
