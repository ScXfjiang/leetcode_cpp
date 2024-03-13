#include <vector>
#include <algorithm>

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> solutions;
  std::vector<int> subset;
  Backtracking(nums, 0, subset, solutions);
  return solutions;
}

void Backtracking(const std::vector<int>& nums, int index, std::vector<int>& subset,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  solutions.push_back(subset);
  for (int i = index; i < nums.size(); ++i) {
    // pruning
    if (i > index && nums[i] == nums[i - 1]) { continue; }
    subset.push_back(nums[i]);
    Backtracking(nums, i + 1, subset, solutions);
    subset.pop_back();
  }
}