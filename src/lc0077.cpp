#include <vector>

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> comb;
  Backtracking(n, k, 1, comb, solutions);
  return solutions;
}

void Backtracking(int n, int k, int start, std::vector<int>& comb,
                  std::vector<std::vector<int>>& solutions) {
  // valid solution (base case)
  if (k == 0) {
    solutions.push_back(comb);
    return;
  }
  for (int i = start; i <= n; ++i) {
    comb.push_back(i);
    Backtracking(n, k - 1, i + 1, comb, solutions);
    comb.pop_back();
  }
}
