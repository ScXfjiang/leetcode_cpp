#include <vector>
#include <queue>

// Solution 1 - DFS
int numEnclaves(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  for (int i = 0; i < m; ++i) {
    DFSSinkLand(grid, i, 0);
    DFSSinkLand(grid, i, n - 1);
  }
  for (int j = 1; j < n - 1; ++j) {
    DFSSinkLand(grid, 0, j);
    DFSSinkLand(grid, m - 1, j);
  }
  int count = 0;
  for (int i = 1; i < m - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (grid[i][j] == 1) { ++count; }
    }
  }
  return count;
}

void DFSSinkLand(std::vector<std::vector<int>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { return; }
  if (grid[i][j] == 0) { return; }
  grid[i][j] = 0;
  DFSSinkLand(grid, i - 1, j);
  DFSSinkLand(grid, i + 1, j);
  DFSSinkLand(grid, i, j - 1);
  DFSSinkLand(grid, i, j + 1);
}

// Solution 2 - BFS
int numEnclaves(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < m; ++i) {
    if (grid[i][0] == 1) { q.emplace(i, 0); }
    if (grid[i][n - 1] == 1) { q.emplace(i, n - 1); }
  }
  for (int j = 1; j < n - 1; ++j) {
    if (grid[0][j] == 1) { q.emplace(0, j); }
    if (grid[m - 1][j] == 1) { q.emplace(m - 1, j); }
  }
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (auto [dr, dy] : dirs) {
      int new_r = r + dr;
      int new_c = c + dy;
      if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == 1) {
        q.emplace(new_r, new_c);
        grid[new_r][new_c] = 0;
      }
    }
  }
  int count = 0;
  for (int i = 1; i < m - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (grid[i][j] == 1) { ++count; }
    }
  }
  return count;
}
