#include <vector>

// Solution - Brute Force (Time Limit Exceeded)
bool IsPrime(int num) {
  if (num <= 1) { return false; }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) { return false; }
  }
  return true;
}

int countPrimes(int n) {
  int count = 0;
  for (int i = 2; i < n; i++) {
    if (IsPrime(i)) { count++; }
  }
  return count;
}

// Solution 2 - Eratosthenes Algorithm
int countPrimes(int n) {
  if (n <= 2) { return 0; }
  std::vector<bool> is_prime(n, true);
  int count = 0;
  for (int p = 2; p * p < n; ++p) {
    if (is_prime[p]) {
      for (int i = p * p; i < n; i += p) { is_prime[i] = false; }
    }
  }
  for (int p = 2; p < n; ++p) {
    if (is_prime[p]) { count++; }
  }
  return count;
}
