#include <string>
#include <stack>
#include <unordered_set>

bool isValid(std::string s) {
  const std::string opening_brackets = "{[(";
  const std::string closing_brackets = "}])";
  std::stack<char> stk;

  for (auto c : s) {
    if (opening_brackets.find(c) != std::string::npos) {  // opening brackets
      stk.push(c);
    } else {  // closing brackets
      // no corresponding opening bracket or opening bracket doesn't match
      if (stk.empty() || stk.top() != opening_brackets[closing_brackets.find(c)]) {
        return false;
      } else {
        stk.pop();
        continue;
      }
    }
  }

  return stk.empty();
}

bool isValid(std::string s) {
  std::stack<char> stk;
  for (char c : s) {
    switch (c) {
      case '(':
      case '{':
      case '[': stk.push(c); break;
      case ')':
        if (!stk.empty() && stk.top() == '(') {
          stk.pop();
          break;
        } else {
          return false;
        }
      case '}':
        if (!stk.empty() && stk.top() == '{') {
          stk.pop();
          break;
        } else {
          return false;
        }
      case ']':
        if (!stk.empty() && stk.top() == '[') {
          stk.pop();
          break;
        } else {
          return false;
        }
    }
  }
  return stk.empty();
}
