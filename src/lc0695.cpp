#include <vector>
#include <iostream>

// Solution 1 - DFS
int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  int max_area = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) {
        int area = 0;
        DFSSinkLandAndIncreaseArea(grid, i, j, area);
        max_area = std::max(max_area, area);
      }
    }
  }
  return max_area;
}

void DFSSinkLandAndIncreaseArea(std::vector<std::vector<int>>& grid, int i, int j,
                                int& area) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { return; }
  if (grid[i][j] != 1) { return; }
  grid[i][j] = 0;
  area += 1;
  DFSSinkLandAndIncreaseArea(grid, i - 1, j, area);
  DFSSinkLandAndIncreaseArea(grid, i + 1, j, area);
  DFSSinkLandAndIncreaseArea(grid, i, j - 1, area);
  DFSSinkLandAndIncreaseArea(grid, i, j + 1, area);
}

// Solution 2 - DFS
int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  int max_area = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) {
        max_area = std::max(max_area, DFSSinkLandAndCalcArea(grid, i, j));
      }
    }
  }
  return max_area;
}

int DFSSinkLandAndCalcArea(std::vector<std::vector<int>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { return 0; }
  if (grid[i][j] != 1) { return 0; }
  grid[i][j] = 0;
  int area = 1;
  area += DFSSinkLandAndCalcArea(grid, i - 1, j);
  area += DFSSinkLandAndCalcArea(grid, i + 1, j);
  area += DFSSinkLandAndCalcArea(grid, i, j - 1);
  area += DFSSinkLandAndCalcArea(grid, i, j + 1);
  return area;
}
