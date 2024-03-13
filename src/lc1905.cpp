#include <vector>

int countSubIslands(std::vector<std::vector<int>>& grid1,
                    std::vector<std::vector<int>>& grid2) {
  int num_subislands = 0;
  for (int i = 0; i < grid2.size(); ++i) {
    for (int j = 0; j < grid2[0].size(); ++j) {
      if (grid2[i][j] == 1) {
        if (DFSCheckSubIsland(grid1, grid2, i, j)) { ++num_subislands; }
      }
    }
  }
  return num_subislands;
}

bool DFSCheckSubIsland(std::vector<std::vector<int>>& grid1,
                       std::vector<std::vector<int>>& grid2, int i, int j) {
  if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size()) { return true; }
  if (grid2[i][j] == 0) { return true; }
  // doesn't meet the condition of a sub-island
  if (grid1[i][j] == 0) { return false; }
  // mark as visited
  grid2[i][j] = 0;
  bool up = DFSCheckSubIsland(grid1, grid2, i - 1, j);
  bool down = DFSCheckSubIsland(grid1, grid2, i + 1, j);
  bool left = DFSCheckSubIsland(grid1, grid2, i, j - 1);
  bool right = DFSCheckSubIsland(grid1, grid2, i, j + 1);
  return up && down && left && right;
}
