#include <vector>
#include <queue>

// Solution - BFS + Record Level
int orangesRotting(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::queue<std::pair<int, int>> q;
  int num_fresh = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 2) { q.emplace(i, j); }
      if (grid[i][j] == 1) { ++num_fresh; }
    }
  }
  int level = 0;
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty() && num_fresh > 0) {
    ++level;
    int level_size = q.size();
    for (int i = 0; i < level_size; ++i) {
      auto [r, c] = q.front();
      q.pop();
      for (auto [dr, dc] : dirs) {
        int new_r = r + dr;
        int new_c = c + dc;
        if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && grid[new_r][new_c] == 1) {
          grid[new_r][new_c] = 2;
          --num_fresh;
          q.emplace(new_r, new_c);
        }
      }
    }
  }
  if (num_fresh > 0) { return -1; }
  return level;
}
