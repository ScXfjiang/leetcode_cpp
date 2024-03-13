#include <vector>
#include <string>

std::vector<std::vector<std::string>> partition(std::string s) {
  std::vector<std::vector<std::string>> solutions;
  std::vector<std::string> part;
  Backtracking(s, 0, part, solutions);
  return solutions;
}

bool isPalindrome(const std::string& s, int start, int end) {
  while (start < end) {
    if (s[start++] != s[end--]) { return false; }
  }
  return true;
}

void Backtracking(const std::string& s, int idx, std::vector<std::string>& part,
                  std::vector<std::vector<std::string>>& solutions) {
  // valid solution (base case)
  if (idx == s.size()) {
    solutions.push_back(part);
    return;
  }
  for (int i = idx; i < s.size(); i++) {
    if (isPalindrome(s, idx, i)) {
      part.push_back(s.substr(idx, i - idx + 1));
      Backtracking(s, i + 1, part, solutions);
      part.pop_back();
    }
  }
}
