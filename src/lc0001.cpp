#include <vector>
#include <unordered_map>
#include <iostream>

// Solution 1 - Brute Force
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) { return {i, j}; }
    }
  }
  return {};
}

// Solution 2 - Two-pass Hash Table
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> val2idx;
  for (int i = 0; i < nums.size(); ++i) { val2idx[nums[i]] = i; }
  for (int i = 0; i < nums.size(); ++i) {
    int comp = target - nums[i];
    if (val2idx.find(comp) != val2idx.end() && val2idx[comp] != i) {
      return {i, val2idx[comp]};
    }
  }
  return {};
}

// Solution 3 - One-pass Hash Table
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> val2comp_idx;
  for (int i = 0; i < nums.size(); ++i) {
    if (val2comp_idx.find(nums[i]) == val2comp_idx.end()) {
      val2comp_idx[target - nums[i]] = i;
    } else {
      return {i, val2comp_idx[nums[i]]};
    }
  }
  return {};
}
