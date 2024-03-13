// Solution 1 - Simulation (Iterative)
bool isPowerOfFour(int n) {
  if (n <= 0) { return false; }
  while (n % 4 == 0) { n /= 4; }
  return n == 1;
}

// Solution 2 - Simulation (Recursion)
bool isPowerOfFour(int n) {
  // edge case
  if (n <= 0) { return false; }
  // base cases
  if (n == 1) { return true; }
  if (n % 4 != 0) { return false; }
  return isPowerOfFour(n / 4);
}

// Solution 3 - Bit Manipulation
bool isPowerOfFour(int n) {
  if (n <= 0) { return false; }
  return (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
}