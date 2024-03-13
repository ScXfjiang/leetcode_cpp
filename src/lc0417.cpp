#include <vector>

void DFS(const std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& can_reach,
         int r, int c) {
  if (can_reach[r][c]) { return; }
  can_reach[r][c] = true;
  std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  for (auto& dir : dirs) {
    int new_r = r + dir.first, new_c = c + dir.second;
    if (new_r >= 0 && new_r < heights.size() && new_c >= 0 && new_c < heights[0].size()
        && heights[new_r][new_c] >= heights[r][c]) {
      DFS(heights, can_reach, new_r, new_c);
    }
  }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
  if (heights.empty()) return {};

  int m = heights.size();
  int n = heights[0].size();
  std::vector<std::vector<bool>> canReachP(m, std::vector<bool>(n, false));
  std::vector<std::vector<bool>> canReachA(m, std::vector<bool>(n, false));
  std::vector<std::vector<int>> result;

  for (int i = 0; i < m; ++i) {
    DFS(heights, canReachP, i, 0);      // Pacific left border
    DFS(heights, canReachA, i, n - 1);  // Atlantic right border
  }

  for (int i = 0; i < n; ++i) {
    DFS(heights, canReachP, 0, i);      // Pacific top border
    DFS(heights, canReachA, m - 1, i);  // Atlantic bottom border
  }

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (canReachP[r][c] && canReachA[r][c]) { result.push_back({r, c}); }
    }
  }

  return result;
}
