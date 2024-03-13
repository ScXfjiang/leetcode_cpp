#include <string>

bool validPalindrome(std::string s) {
  int left = 0;
  int right = s.size() - 1;

  auto IsPalindrome = [&s](int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) { return false; }
      ++l;
      --r;
    }
    return true;
  };

  while (left < right) {
    if (s[left] != s[right]) {
      return IsPalindrome(left + 1, right) || IsPalindrome(left, right - 1);
    }
    ++left;
    --right;
  }
  return true;
}
