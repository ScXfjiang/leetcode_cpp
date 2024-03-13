#include <vector>
#include <unordered_map>
#include <string>

std::vector<std::string> letterCombinations(std::string digits) {
  if (digits.empty()) { return {}; }
  std::string str;
  std::unordered_map<char, std::string> digit2letters = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                                         {'8', "tuv"}, {'9', "wxyz"}};
  std::vector<std::string> solutions;
  Backtracking(digits, 0, digit2letters, str, solutions);
  return solutions;
}

void Backtracking(const std::string& digits, int idx,
                  const std::unordered_map<char, std::string>& digit2letters, std::string& str,
                  std::vector<std::string>& solutions) {
  // valid solution (base case)
  if (idx == digits.size()) {
    solutions.push_back(str);
    return;
  }
  const std::string& letters = digit2letters.at(digits[idx]);
  for (char letter : letters) {
    str.push_back(letter);
    Backtracking(digits, idx + 1, digit2letters, str, solutions);
    str.pop_back();
  }
}