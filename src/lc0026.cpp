#include <vector>

// Solution 1 - std::unique
int removeDuplicates(std::vector<int>& nums) {
  return std::unique(nums.begin(), nums.end()) - nums.begin();
}

// Solution 2
int removeDuplicates(std::vector<int>& nums) {
  if (nums.size() <= 1) { return nums.size(); }
  int i = 1;  // past-the-end idx of reserved part
  for (int j = 1; j < nums.size(); ++j) {
    if (nums[j] != nums[i - 1]) { nums[i++] = nums[j]; }
  }
  return i;
}
