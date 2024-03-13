#include <vector>
#include <queue>
#include <limits>

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
  int m = mat.size();
  int n = mat[0].size();
  std::vector<std::vector<int>> dist(m,
                                     std::vector<int>(n, std::numeric_limits<int>::max()));
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        dist[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (auto [dr, dc] : dirs) {
      int new_r = r + dr;
      int new_c = c + dc;
      if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
        if (dist[new_r][new_c] > dist[r][c] + 1) {
          dist[new_r][new_c] = dist[r][c] + 1;
          q.emplace(new_r, new_c);
        }
      }
    }
  }
  return dist;
}
