#include <string>
#include <stack>
#include <cctype>

int calculate(std::string s) {
  int result = 0;  // current result
  int number = 0;  // current number
  int sign = 1;    // current sign, 1 means positive, -1 means negative
  std::stack<int> stk;

  for (char c : s) {
    if (std::isdigit(c)) {
      // build the current number
      number = 10 * number + (c - '0');
    } else if (c == '+') {
      result += sign * number;  // add previous number to result
      number = 0;               // reset number to zero
      sign = 1;                 // set sign to positive
    } else if (c == '-') {
      result += sign * number;  // add previous number to result
      number = 0;               // reset number to zero
      sign = -1;                // set sign to negative
    } else if (c == '(') {
      // new expression in parenthesis
      // push result and sign onto stack
      stk.push(result);
      stk.push(sign);
      // reset sign and result for expression in parenthesis
      sign = 1;
      result = 0;
    } else if (c == ')') {
      // end of expression in parenthesis
      // evaluate result for expression in parenthesis, then add it to result
      result += sign * number;
      // reset number to zero
      number = 0;
      // get sign before the parenthesis
      result *= stk.top();
      stk.pop();
      // get result calculated before parenthesis, then add it to result
      result += stk.top();
      stk.pop();
    }
  }

  // there might be a number left at the end when there is no sign after it
  if (number != 0) result += sign * number;

  return result;
}
