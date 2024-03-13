// Solution - Mathematical Derivation
int trailingZeroes(int n) {
  int count = 0;
  for (int i = 5; i <= n; ++i) {
    int j = i;
    while (j % 5 == 0) {
      ++count;
      j /= 5;
    }
  }
  return count;
}

// Solution - Mathematical Derivation, Optimized
int trailingZeroes(int n) {
  int count = 0;
  for (int i = 5; n / i >= 1; i *= 5) { count += n / i; }
  return count;
}