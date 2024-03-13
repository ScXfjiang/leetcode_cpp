#include <vector>
#include <algorithm>
#include <numeric>

// Solution - Prefix Sum
long long gridGame(std::vector<std::vector<int>>& grid) {
  int n = grid[0].size();
  std::vector<long> top_prefix_sum(n + 1, 0);
  std::vector<long> bottom_prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    top_prefix_sum[i] = grid[0][i - 1] + top_prefix_sum[i - 1];
    bottom_prefix_sum[i] = grid[1][i - 1] + bottom_prefix_sum[i - 1];
  }
  long long max_second_robot = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    long long top_sum = top_prefix_sum[n] - top_prefix_sum[i + 1];
    long long bottom_sum = bottom_prefix_sum[i];
    max_second_robot = std::min(max_second_robot, std::max(top_sum, bottom_sum));
  }
  return max_second_robot;
}

// Solution - Prefix Sum, Optimized
long long gridGame(std::vector<std::vector<int>>& grid) {
  long long top_sum = std::accumulate(grid[0].begin(), grid[0].end(), 0LL);
  long long bottom_sum = 0;
  long long max_second_robot = LLONG_MAX;
  for (int i = 0; i < grid[0].size(); ++i) {
    top_sum -= grid[0][i];
    max_second_robot = std::min(max_second_robot, std::max(top_sum, bottom_sum));
    bottom_sum += grid[1][i];
  }
  return max_second_robot;
}
