#include <vector>
#include <queue>

// Solution 1 - DFS
int numIslands(std::vector<std::vector<char>>& grid) {
  int num_island = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        DFSSinkLand(grid, i, j);
        ++num_island;
      }
    }
  }
  return num_island;
}

void DFSSinkLand(std::vector<std::vector<char>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { return; }
  if (grid[i][j] == '0') { return; }
  grid[i][j] = '0';
  DFSSinkLand(grid, i - 1, j);
  DFSSinkLand(grid, i + 1, j);
  DFSSinkLand(grid, i, j - 1);
  DFSSinkLand(grid, i, j + 1);
}

// Solution 2 - BFS
int numIslands(std::vector<std::vector<char>>& grid) {
  if (grid.empty()) { return 0; }
  int num_island = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        BFS(grid, i, j);
        ++num_island;
      }
    }
  }
  return num_island;
}

void BFS(std::vector<std::vector<char>>& grid, int i, int j) {
  std::queue<std::pair<int, int>> q;
  q.emplace(i, j);
  grid[i][j] = '0';
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (auto [dr, dc] : dirs) {
      int new_r = r + dr;
      int new_c = c + dc;
      if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size()
          && grid[new_r][new_c] == '1') {
        q.emplace(new_r, new_c);
        grid[new_r][new_c] = '0';
      }
    }
  }
}

// Solution 3 - BFS (Time Limit Exceeded)
int numIslands(std::vector<std::vector<char>>& grid) {
  if (grid.empty()) { return 0; }
  int num_island = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        BFSSinkLand(grid, i, j);
        ++num_island;
      }
    }
  }
  return num_island;
}

void BFSSinkLand(std::vector<std::vector<char>>& grid, int i, int j) {
  std::queue<std::pair<int, int>> q;
  q.emplace(i, j);
  grid[i][j] = '0';
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    grid[r][c] = '0';
    for (auto [dr, dc] : dirs) {
      int new_r = r + dr;
      int new_c = c + dc;
      if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size()
          && grid[new_r][new_c] == '1') {
        q.emplace(new_r, new_c);
      }
    }
  }
}
