#include <string>
#include <algorithm>

std::string addStrings(std::string num1, std::string num2) {
  std::string sum_str;
  int carry = 0;
  int i = num1.size() - 1;
  int j = num2.size() - 1;
  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) {
      sum += num1[i] - '0';
      --i;
    }
    if (j >= 0) {
      sum += num2[j] - '0';
      --j;
    }
    sum_str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  std::reverse(sum_str.begin(), sum_str.end());
  return sum_str;
}
