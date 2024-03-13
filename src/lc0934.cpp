#include <vector>
#include <queue>

int shortestBridge(std::vector<std::vector<int>>& grid) {
  // find and mark the first island (grid[i][j] == 2)
  std::queue<std::pair<int, int>> q;
  bool found = false;
  for (int i = 0; i < grid.size(); ++i) {
    if (found) { break; }
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) {
        DFSMarkFirstIsland(grid, i, j, q);
        found = true;
        break;
      }
    }
  }
  // expand the first island until we reach the second one
  int num_step = 0;
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    int level_size = q.size();
    for (int i = 0; i < level_size; ++i) {
      auto [r, c] = q.front();
      q.pop();
      for (auto [dr, dc] : dirs) {
        int new_r = r + dr;
        int new_c = c + dc;
        if (new_r >= 0 && new_c >= 0 && new_r < grid.size() && new_c < grid[0].size()
            && grid[new_r][new_c] != 2) {
          if (grid[new_r][new_c] == 1) { return num_step; }
          q.emplace(new_r, new_c);
          grid[new_r][new_c] = 2;
        }
      }
    }
    ++num_step;
  }
  return -1;
}

void DFSMarkFirstIsland(std::vector<std::vector<int>>& grid, int r, int c,
                        std::queue<std::pair<int, int>>& q) {
  if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) { return; }
  if (grid[r][c] != 1) { return; }
  grid[r][c] = 2;
  q.emplace(r, c);
  DFSMarkFirstIsland(grid, r - 1, c, q);
  DFSMarkFirstIsland(grid, r + 1, c, q);
  DFSMarkFirstIsland(grid, r, c - 1, q);
  DFSMarkFirstIsland(grid, r, c + 1, q);
}
