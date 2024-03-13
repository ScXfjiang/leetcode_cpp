#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <limits>

// Solution 1 - Sliding Window
bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
  std::unordered_set<int> seen;
  for (int i = 0; i < nums.size(); ++i) {
    if (i > k) { seen.erase(nums[i - (k + 1)]); }
    if (!seen.insert(nums[i]).second) { return true; }
  }
  return false;
}

// Solution 2 - Sliding Window + Hash Map
bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> num2last_idx;
  for (int i = 0; i < nums.size(); ++i) {
    if (num2last_idx.find(nums[i]) != num2last_idx.end()
        && std::abs(i - num2last_idx[nums[i]]) <= k) {
      return true;
    }
    num2last_idx[nums[i]] = i;
  }
  return false;
}
