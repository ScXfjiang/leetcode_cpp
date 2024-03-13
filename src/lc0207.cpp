#include <vector>

bool DetectCycleFromNode(std::vector<std::vector<int>>& graph, int course,
                         std::vector<bool>& visited, std::vector<bool>& on_path) {
  if (course < 0 || course >= graph.size()) { return false; }
  if (on_path[course]) { return true; }
  if (visited[course]) { return false; }

  visited[course] = true;
  on_path[course] = true;
  for (int neighbor : graph[course]) {
    if (DetectCycleFromNode(graph, neighbor, visited, on_path)) { return true; }
  }
  on_path[course] = false;

  return false;
}

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
  // build graph
  std::vector<std::vector<int>> graph(numCourses);
  for (const auto& pre : prerequisites) { graph[pre[1]].push_back(pre[0]); }

  // detect cycles
  std::vector<bool> visited(numCourses, false);
  std::vector<bool> on_path(numCourses, false);
  for (int i = 0; i < numCourses; ++i) {
    if (visited[i]) { continue; }
    if (DetectCycleFromNode(graph, i, visited, on_path)) { return false; }
  }

  return true;
}
