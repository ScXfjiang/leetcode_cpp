#include <vector>

std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> perm;
  std::vector<bool> used(nums.size(), false);
  Backtracking(nums, used, perm, solutions);
  return solutions;
}

void Backtracking(const std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& perm,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  if (perm.size() == nums.size()) {
    solutions.push_back(perm);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    // pruning
    if (used[i]) { continue; }
    used[i] = true;
    perm.push_back(nums[i]);
    Backtracking(nums, used, perm, solutions);
    used[i] = false;
    perm.pop_back();
  }
}
