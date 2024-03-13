#include <vector>

int removeDuplicates(std::vector<int>& nums) {
  if (nums.size() <= 2) { return nums.size(); }
  int i = 2;  // past-the-end idx of reserved part
  for (int j = 2; j < nums.size(); ++j) {
    if (nums[j] != nums[i - 2]) { nums[i++] = nums[j]; }
  }
  return i;
}
