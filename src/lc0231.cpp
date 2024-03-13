// Solution 1 - Simulation (Iterative)
bool isPowerOfTwo(int n) {
  if (n <= 0) { return false; }
  while (n % 2 == 0) { n /= 2; }
  return n == 1;
}

// Solution 2 - Simulation (Recursion)
bool isPowerOfTwo(int n) {
  // edge case
  if (n <= 0) { return false; }
  // base cases
  if (n == 1) { return true; }
  if (n % 2 != 0) { return false; }
  return isPowerOfTwo(n / 2);
}

// Solution 3 - Bit Manipulation
bool isPowerOfTwo(int n) {
  if (n <= 0) { return false; }
  return (n & (n - 1)) == 0;
}
