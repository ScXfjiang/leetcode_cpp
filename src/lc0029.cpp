#include <iostream>
#include <limits>

// Solution 1 - Repeated Subtraction (Time Limit Exceeded)
int divide(int dividend, int divisor) {
  // edge case - overflow
  if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
    return std::numeric_limits<int>::max();
  }
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
  // use long type to avoid overflow
  long cur_dividend = std::abs(static_cast<long>(dividend));
  long cur_divisor = std::abs(static_cast<long>(divisor));
  long quotient = 0;
  while (cur_dividend >= cur_divisor) {
    cur_dividend -= cur_divisor;
    quotient++;
  }
  return sign * quotient;
}

// Solution 2 - Bit Manipulation
int divide(int dividend, int divisor) {
  // edge case - overflow
  if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
    return std::numeric_limits<int>::max();
  }
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
  // use long type to avoid overflow
  long cur_dividend = std::abs(static_cast<long>(dividend));
  long cur_divisor = std::abs(static_cast<long>(divisor));
  long quotient = 0;
  while (cur_dividend >= cur_divisor) {
    long tmp = cur_divisor;
    long multiple = 1;
    while (cur_dividend >= (tmp << 1)) {
      tmp <<= 1;
      multiple <<= 1;
    }
    cur_dividend -= tmp;
    quotient += multiple;
  }
  return sign * quotient;
}
