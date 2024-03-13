#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2) {
  if (num1 == "0" || num2 == "0") { return "0"; }
  int n1 = num1.size();
  int n2 = num2.size();
  std::vector<int> res_vec(n1 + n2, 0);
  for (int i = n1 - 1; i >= 0; --i) {
    for (int j = n2 - 1; j >= 0; --j) {
      int mul = res_vec[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
      res_vec[i + j + 1] = mul % 10;
      res_vec[i + j] += mul / 10;
    }
  }
  std::string res_str;
  int i = 0;
  while (i < res_vec.size() && res_vec[i] == 0) { ++i; }
  while (i < res_vec.size()) {
    res_str.push_back(res_vec[i] + '0');
    ++i;
  }
  return res_str;
}
