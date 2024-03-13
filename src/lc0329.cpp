#include <iostream>
#include <vector>
#include <algorithm>

// Utility function to perform DFS and memoization
int dfs(const std::vector<std::vector<int>>& matrix, int i, int j,
        std::vector<std::vector<int>>& memo) {
  // If we already know the longest path from this cell, return it
  if (memo[i][j] != 0) { return memo[i][j]; }

  // Directions in which we can move: up, down, left, right
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  // Initialize the length of the longest path from this cell
  int max_path = 1;

  // Explore all the possible directions
  for (const auto& dir : dirs) {
    int x = i + dir.first, y = j + dir.second;

    // Check if the new position is within bounds and the value is greater than the current
    // cell
    if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size()
        && matrix[x][y] > matrix[i][j]) {
      // DFS from the new position
      int len = 1 + dfs(matrix, x, y, memo);
      // Update the longest path from the current cell
      max_path = std::max(max_path, len);
    }
  }

  // Memoize the result
  memo[i][j] = max_path;
  return max_path;
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
  int longest_path = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      longest_path = std::max(longest_path, dfs(matrix, i, j, memo));
    }
  }
  return longest_path;
}
