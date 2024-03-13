#include <string>
#include <algorithm>

std::string convertToBase7(int num) {
  // edge case
  if (num == 0) { return "0"; }
  std::string base7;
  bool is_negative = num < 0;
  num = std::abs(num);
  while (num > 0) {
    base7.push_back('0' + (num % 7));
    num /= 7;
  }
  if (is_negative) { base7.push_back('-'); }
  std::reverse(base7.begin(), base7.end());
  return base7;
}
