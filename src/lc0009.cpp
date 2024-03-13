bool isPalindrome(int x) {
  if (x < 0) { return false; }
  long reversed = 0;
  long tmp = x;
  while (tmp != 0) {
    int digit = tmp % 10;
    reversed = reversed * 10 + digit;
    tmp /= 10;
  }
  return reversed == x;
}
