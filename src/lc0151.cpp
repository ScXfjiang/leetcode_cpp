#include <sstream>
#include <stack>
#include <string>

// Solution 1 - std::istringstream
std::string reverseWords(std::string s) {
  std::stack<std::string> stk;
  std::istringstream iss(s);
  std::string word;
  while (iss >> word) { stk.push(word); }
  std::string reversed_str;
  while (!stk.empty()) {
    reversed_str.append(stk.top());
    stk.pop();
    if (!stk.empty()) { reversed_str.append(" "); }
  }
  return reversed_str;
}

// Solution 2
std::string reverseWords(std::string s) {
  std::string reversed_str = "";
  int j = s.size() - 1;
  while (j >= 0) {
    while (j >= 0 && s[j] == ' ') { --j; }
    if (j < 0) { break; }
    int i = j - 1;
    while (i >= 0 && s[i] != ' ') { --i; }
    reversed_str += s.substr(i + 1, j - i) + " ";
    j = i - 1;
  }
  return reversed_str.substr(0, reversed_str.size() - 1);
}