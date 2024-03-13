int hammingDistance(int x, int y) {
  int xor_val = x ^ y;
  int distance = 0;
  while (xor_val) {
    distance += xor_val & 1;
    xor_val >>= 1;
  }
  return distance;
}
