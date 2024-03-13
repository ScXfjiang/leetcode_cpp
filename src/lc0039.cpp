#include <vector>

// Solution 1: backtracking
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> comb;
  Backtracking(candidates, target, 0, comb, solutions);
  return solutions;
}

void Backtracking(const std::vector<int>& candidates, int target, int start, std::vector<int>& comb,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  if (target == 0) {
    solutions.push_back(comb);
    return;
  }
  for (int i = start; i < candidates.size(); ++i) {
    // pruning
    if (candidates[i] > target) { continue; }
    comb.push_back(candidates[i]);
    Backtracking(candidates, target - candidates[i], i, comb, solutions);
    comb.pop_back();
  }
}

// Solution 2: backtracking
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> comb;
  std::sort(candidates.begin(), candidates.end());
  Backtracking(candidates, target, 0, comb, solutions);
  return solutions;
}

void Backtracking(const std::vector<int>& candidates, int target, int start, std::vector<int>& comb,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  if (target == 0) {
    solutions.push_back(comb);
    return;
  }
  for (int i = start; i < candidates.size(); ++i) {
    // pruning
    if (candidates[i] > target) { break; }
    comb.push_back(candidates[i]);
    Backtracking(candidates, target - candidates[i], i, comb, solutions);
    comb.pop_back();
  }
}
