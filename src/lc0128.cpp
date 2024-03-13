#include <vector>
#include <unordered_set>

// Solution 1 - Hash Set
int longestConsecutive(std::vector<int>& nums) {
  std::unordered_set<int> set(nums.begin(), nums.end());
  int max_len = 0;
  for (int num : nums) {
    // check if num is the start of a sequence
    if (set.find(num - 1) == set.end()) {
      int cur_num = num;
      int cur_len = 1;
      while (set.find(cur_num + 1) != set.end()) {
        ++cur_num;
        ++cur_len;
      }
      max_len = std::max(max_len, cur_len);
    }
  }
  return max_len;
}

// Solution 2 - Sorting
int longestConsecutive(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  auto it = std::unique(nums.begin(), nums.end());
  nums.erase(it, nums.end());
  int max_len = 0;
  int i = 0;
  for (int i = 0; i < nums.size(); ++i) {
    int cur_len = 1;
    while (i < nums.size() - 1 && nums[i] == nums[i + 1] - 1) {
      ++cur_len;
      ++i;
    }
    max_len = std::max(max_len, cur_len);
  }
  return max_len;
}
