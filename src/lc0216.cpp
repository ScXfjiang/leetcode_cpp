#include <vector>

std::vector<std::vector<int>> combinationSum3(int k, int target) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> comb;
  Backtracking(k, target, 1, comb, solutions);
  return solutions;
}

void Backtracking(int k, int target, int start, std::vector<int>& comb,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  if (k == 0 && target == 0) {
    solutions.push_back(comb);
    return;
  }
  for (int i = start; i <= 9; ++i) {
    // pruning
    if (i > target) { break; }
    comb.push_back(i);
    Backtracking(k - 1, target - i, i + 1, comb, solutions);
    comb.pop_back();
  }
}
