
// Solution 1 - Simulation (Iterative)
int addDigits(int num) {
  while (num >= 10) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    num = sum;
  }
  return num;
}

// Solution 2 - Simulation (Recursion)
int addDigits(int num) {
  if (num < 10) { return num; }
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return addDigits(sum);
}

// Solution 3 - Mathematical Formula
int addDigits(int num) {
  if (num == 0) { return 0; }
  return num % 9 == 0 ? 9 : num % 9;
}

// Solution 4 - Mathematical Formula, Optimized
int addDigits(int num) {
  if (num == 0) { return 0; }
  return 1 + (num - 1) % 9;
}
