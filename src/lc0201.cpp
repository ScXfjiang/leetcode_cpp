int rangeBitwiseAnd(int left, int right) {
  int shift = 0;
  // find common prefix of numbers in range [left, right]
  while (left < right) {
    left >>= 1;
    right >>= 1;
    ++shift;
  }
  // shift prefix back to the original position
  return left << shift;
}
