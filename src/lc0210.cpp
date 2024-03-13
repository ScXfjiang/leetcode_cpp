#include <vector>

bool DetectCycleFromNodeAndStorePath(const std::vector<std::vector<int>>& graph, int course,
                                     std::vector<bool>& visited, std::vector<bool>& on_path,
                                     std::vector<int>& path) {
  if (course < 0 || course >= graph.size()) { return false; }
  if (on_path[course]) { return true; }
  if (visited[course]) { return false; }

  on_path[course] = true;
  visited[course] = true;
  for (int neighbor : graph[course]) {
    if (DetectCycleFromNodeAndStorePath(graph, neighbor, visited, on_path, path)) { return true; }
  }
  on_path[course] = false;

  path.push_back(course);

  return false;
}

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  for (const auto& p : prerequisites) { graph[p[1]].push_back(p[0]); }

  std::vector<bool> visited(numCourses, false);
  std::vector<bool> on_path(numCourses, false);
  std::vector<int> path;
  for (int i = 0; i < numCourses; ++i) {
    if (visited[i]) { continue; }
    // cycle detected
    if (DetectCycleFromNodeAndStorePath(graph, i, visited, on_path, path)) { return {}; }
  }
  // no cycle
  std::reverse(path.begin(), path.end());

  return path;
}
