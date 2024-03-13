#include <vector>

// Solution 1 - DP
std::vector<int> countBits(int n) {
  std::vector<int> cnt(n + 1);
  cnt[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) {
      cnt[i] = cnt[i / 2];
    } else {
      cnt[i] = cnt[i / 2] + 1;
    }
  }
  return cnt;
}

// Solution 1 - DP, Optimized
std::vector<int> countBits(int n) {
  std::vector<int> cnt(n + 1);
  cnt[0] = 0;
  for (int i = 1; i <= n; ++i) { cnt[i] = cnt[i >> 1] + (i & 1); }
  return cnt;
}
