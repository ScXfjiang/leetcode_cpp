#include <string>

// Solution 1
int strStr(std::string haystack, std::string needle) {
  int pos = haystack.find(needle);
  if (pos != std::string::npos) {
    return pos;
  } else {
    return -1;
  }
}

// Solution 2
int strStr(const std::string& haystack, const std::string& needle) {
  int n = haystack.size();
  int m = needle.size();
  for (int i = 0; i <= n - m; ++i) {
    if (haystack.substr(i, m) == needle) { return i; }
  }
  return -1;
}