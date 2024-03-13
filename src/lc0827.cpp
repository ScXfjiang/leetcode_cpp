#include <vector>
#include <unordered_set>

int largestIsland(std::vector<std::vector<int>>& grid) {
  int max_size = 0;
  // 1. identify and mark islands and calculate their sizes
  std::unordered_map<int, int> id2size;
  int id = 2;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == 1) {
        int size = DFSMarkIslandAndCalcSize(grid, i, j, id);
        id2size[id++] = size;
        max_size = std::max(max_size, size);
      }
    }
  }
  // 2. flip each 0 to 1 to connect islands
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 0) {
        int new_size = 1;
        std::unordered_set<int> visited;
        std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dr, dc] : dirs) {
          int new_r = i + dr;
          int new_c = j + dc;
          if (new_r >= 0 && new_c >= 0 && new_r < grid.size() && new_c < grid[0].size()
              && grid[new_r][new_c] > 1) {
            int id = grid[new_r][new_c];
            if (visited.find(id) != visited.end()) { continue; }
            visited.insert(id);
            new_size += id2size[id];
          }
        }
        max_size = std::max(max_size, new_size);
      }
    }
  }
  return max_size;
}

int DFSMarkIslandAndCalcSize(std::vector<std::vector<int>>& grid, int i, int j, int id) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) { return 0; }
  if (grid[i][j] != 1) { return 0; }
  grid[i][j] = id;
  int size = 1;
  size += DFSMarkIslandAndCalcSize(grid, i - 1, j, id);
  size += DFSMarkIslandAndCalcSize(grid, i + 1, j, id);
  size += DFSMarkIslandAndCalcSize(grid, i, j - 1, id);
  size += DFSMarkIslandAndCalcSize(grid, i, j + 1, id);
  return size;
}
