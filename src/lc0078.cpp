#include <vector>

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> subset;
  Backtracking(nums, 0, subset, solutions);
  return solutions;
}

void Backtracking(std::vector<int>& nums, int start, std::vector<int>& subset,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  solutions.push_back(subset);
  for (int i = start; i < nums.size(); i++) {
    subset.push_back(nums[i]);
    Backtracking(nums, i + 1, subset, solutions);
    subset.pop_back();
  }
}
