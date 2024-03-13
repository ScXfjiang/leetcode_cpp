#include <vector>
#include <string>

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> solutions;
  std::string comb;
  Backtracking(n, 0, 0, comb, solutions);
  return solutions;
}

void Backtracking(int n, int open, int close, std::string& comb,
                  std::vector<std::string>& solutions) {
  // valid solution (base case)
  if (comb.size() == n * 2) {
    solutions.push_back(comb);
    return;
  }
  if (open < n) {
    comb.push_back('(');
    Backtracking(n, open + 1, close, comb, solutions);
    comb.pop_back();
  }
  if (close < open) {
    comb.push_back(')');
    Backtracking(n, open, close + 1, comb, solutions);
    comb.pop_back();
  }
}
