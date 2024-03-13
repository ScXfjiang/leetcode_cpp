int getSum(int a, int b) {
  while (b != 0) {
    // calculate carry and shift it left
    int carry = (a & b) << 1;

    // perform the sum without carrying
    a = a ^ b;

    // b becomes the carry
    b = carry;
  }
  return a;
}

int getSum(int a, int b) {
  do {
    int sum = a ^ b;
    int carry = (a & b) << 1;
  } while (carry);
  return a;
}