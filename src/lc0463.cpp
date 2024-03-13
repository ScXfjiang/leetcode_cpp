#include <vector>

// Solution 1 - Brute Force
int islandPerimeter(std::vector<std::vector<int>>& grid) {
  int perimeter = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == 1) {
        if (i == 0 || grid[i - 1][j] == 0) { perimeter++; }
        if (i == grid.size() - 1 || grid[i + 1][j] == 0) { perimeter++; }
        if (j == 0 || grid[i][j - 1] == 0) { perimeter++; }
        if (j == grid[0].size() - 1 || grid[i][j + 1] == 0) { perimeter++; }
      }
    }
  }
  return perimeter;
}

// Solution 2 - Count Lands and Connections
int islandPerimeter(std::vector<std::vector<int>>& grid) {
  int num_lands = 0;
  int num_connections = 0;
  int m = grid.size();
  int n = grid[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        ++num_lands;
        if (j < n - 1 && grid[i][j + 1] == 1) { ++num_connections; }
        if (i < m - 1 && grid[i + 1][j] == 1) { ++num_connections; }
      }
    }
  }
  return 4 * num_lands - 2 * num_connections;
}
