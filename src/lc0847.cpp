#include <vector>
#include <queue>

int shortestPathLength(std::vector<std::vector<int>>& graph) {
  int n = graph.size();
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(1 << n, false));
  // tuple = {node, visited state, path length}
  std::queue<std::tuple<int, int, int>> q;
  for (int i = 0; i < n; ++i) {
    q.push({i, 1 << i, 1});
    visited[i][1 << i] = true;
  }
  while (!q.empty()) {
    auto [node, state, path_len] = q.front();
    q.pop();
    // all nodes are visited
    if (state == (1 << n) - 1) { return path_len - 1; }
    for (int neighbor : graph[node]) {
      int next_state = state | (1 << neighbor);
      if (!visited[neighbor][next_state]) {
        visited[neighbor][next_state] = true;
        q.push({neighbor, next_state, path_len + 1});
      }
    }
  }
  return -1;
}
