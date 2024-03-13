// Solution 1 - Without Casting
double myPow(double x, int n) {
  // n is negative
  if (n < 0) {
    x = 1 / x;
    // avoid overflow when n is std::numeric_limits<int>::min().
    n = -(n + 1);
    return x * PosPow(x, n);
  }
  // n is positive
  return PosPow(x, n);
}

double PosPow(double x, int n) {
  // base case - power 0
  if (n == 0) { return 1.0; }
  double half = PosPow(x, n / 2);
  if (n % 2 == 0) {
    return half * half;
  } else {
    return half * half * x;
  }
}

// Solution 2 - With Casting
double myPow(double x, int n) {
  // n is negative
  if (n < 0) {
    x = 1 / x;
    long ln = -1 * static_cast<long>(n);
    return PosPow(x, n);
  }
  // n is positive
  return PosPow(x, n);
}

double PosPow(double x, long n) {
  // base case - power 0
  if (n == 0) { return 1.0; }
  double half = PosPow(x, n / 2);
  if (n % 2 == 0) {
    return half * half;
  } else {
    return half * half * x;
  }
}