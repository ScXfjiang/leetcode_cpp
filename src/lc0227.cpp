#include <stack>
#include <string>

int calculate(std::string s) {
  std::stack<int> stk;
  long long currentNumber = 0;
  char operation = '+';
  for (int i = 0; i < s.length(); i++) {
    char currentChar = s[i];
    if (isdigit(currentChar)) { currentNumber = (currentNumber * 10) + (currentChar - '0'); }
    if (!isdigit(currentChar) && !isspace(currentChar) || i == s.length() - 1) {
      if (operation == '-') {
        stk.push(-currentNumber);
      } else if (operation == '+') {
        stk.push(currentNumber);
      } else if (operation == '*') {
        int stackTop = stk.top();
        stk.pop();
        stk.push(stackTop * currentNumber);
      } else if (operation == '/') {
        int stackTop = stk.top();
        stk.pop();
        stk.push(stackTop / currentNumber);
      }
      operation = currentChar;  // save the current operation
      currentNumber = 0;        // reset number for next iteration
    }
  }
  int result = 0;
  while (!stk.empty()) {
    result += stk.top();
    stk.pop();
  }
  return result;
}
