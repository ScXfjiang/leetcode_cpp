#include <vector>
#include <unordered_set>

// Solution 1 - Hash Set
bool containsDuplicate(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  for (int num : nums) {
    if (!seen.insert(num).second) { return true; }
  }
  return false;
}

// Solution 2 - Sorting
bool containsDuplicate(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] == nums[i + 1]) { return true; }
  }
  return false;
}
