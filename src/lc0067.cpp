#include <string>
#include <algorithm>

std::string addBinary(std::string a, std::string b) {
  std::string sum_str = "";
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) {
      sum += a[i] - '0';
      --i;
    }
    if (j >= 0) {
      sum += b[j] - '0';
      --j;
    }
    sum_str.push_back((sum % 2) + '0');
    carry = sum / 2;
  }
  std::reverse(sum_str.begin(), sum_str.end());
  return sum_str;
}
