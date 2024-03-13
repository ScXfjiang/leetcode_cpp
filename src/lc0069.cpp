// Solution 1 - Binary Search
int mySqrt(int x) {
  if (x < 2) { return x; }
  long left = 1;
  long right = x / 2;
  while (left <= right) {
    long mid = left + (right - left) / 2;
    long sq = mid * mid;
    if (sq == x) {
      return mid;
    } else if (sq < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}

// Solution 2 - Newton's Method
int mySqrt(int x) {
  if (x == 0) { return 0; }
  long r = x;
  while (r * r > x) { r = (r + x / r) / 2; }
  return r;
}