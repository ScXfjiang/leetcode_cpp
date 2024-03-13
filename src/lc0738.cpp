#include <string>

int monotoneIncreasingDigits(int num) {
  std::string s = std::to_string(num);
  int n = s.size();
  int marker = n;
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] > s[i + 1]) {
      marker = i;
      s[i] -= 1;
    }
  }
  for (int i = marker + 1; i < n; ++i) { s[i] = '9'; }
  return std::stoi(s);
}
