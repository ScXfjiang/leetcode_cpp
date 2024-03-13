bool isHappy(int n) {
  int slow = n;
  int fast = n;
  do {
    slow = SumSquares(slow);
    fast = SumSquares(fast);
    fast = SumSquares(fast);
  } while (slow != fast);
  return slow == 1;
}

int SumSquares(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}
