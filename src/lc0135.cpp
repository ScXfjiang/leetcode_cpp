#include <vector>
#include <numeric>

int candy(std::vector<int>& ratings) {
  int n = ratings.size();
  if (n <= 1) { return n; }
  std::vector<int> candy(n, 1);
  for (int i = 1; i < n; ++i) {
    if (ratings[i] > ratings[i - 1]) { candy[i] = candy[i - 1] + 1; }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (ratings[i] > ratings[i + 1]) { candy[i] = std::max(candy[i], candy[i + 1] + 1); }
  }
  return std::accumulate(candy.begin(), candy.end(), 0);
}
