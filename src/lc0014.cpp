#include <string>
#include <vector>

// Solution 1
std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::string prefix = strs[0];
  for (int i = 1; i < strs.size(); ++i) {
    while (strs[i].find(prefix) != 0) {
      prefix.erase(prefix.size() - 1);
      if (prefix.empty()) { return ""; }
    }
  }
  return prefix;
}

// Solution 2 - Sort
std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::sort(begin(strs), end(strs));
  std::string prefix = "";
  std::string first = strs.front();
  std::string last = strs.back();
  for (int i = 0; i < first.size(); ++i) {
    if (first[i] == last[i]) {
      prefix.push_back(first[i]);
    } else {
      break;
    }
  }
  return prefix;
}