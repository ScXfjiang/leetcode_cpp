#include <iostream>
#include <stack>
#include <string>

std::string removeDuplicates(std::string s) {
  std::stack<char> stk;
  for (char c : s) {
    if (!stk.empty() && stk.top() == c) {
      stk.pop();
    } else {
      stk.push(c);
    }
  }
  std::string result;
  while (!stk.empty()) {
    result += stk.top();
    stk.pop();
  }
  std::reverse(result.begin(), result.end());
  return result;
}
