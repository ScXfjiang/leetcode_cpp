#include <string>
#include <algorithm>

bool isPalindrome(std::string s) {
  auto left = s.begin();
  auto right = s.end() - 1;
  while (left < right) {
    if (!std::isalnum(*left)) {
      ++left;
      continue;
    }
    if (!std::isalnum(*right)) {
      --right;
      continue;
    }
    if (std::tolower(*left) != std::tolower(*right)) { return false; }
    ++left;
    --right;
  }
  return true;
}
