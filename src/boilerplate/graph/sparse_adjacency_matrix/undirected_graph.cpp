#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

void Connect(std::unordered_map<int, std::unordered_map<int, int>>& graph, int x, int y,
             int w) {
  graph[x][y] = w;
  graph[y][x] = w;
}

void DFSVisit(std::unordered_map<int, std::unordered_map<int, int>>& graph, int node,
              std::vector<bool>& visited);

void DFS(std::unordered_map<int, std::unordered_map<int, int>>& graph,
         std::vector<int>& start_nodes) {
  // we can guarantee visited vector is always up to date because it is passed by reference
  std::vector<bool> visited(graph.size(), false);
  for (auto node : start_nodes) {
    if (!visited[node]) { DFSVisit(graph, node, visited); }
  }
}

void DFSVisit(std::unordered_map<int, std::unordered_map<int, int>>& graph, int node,
              std::vector<bool>& visited) {
  // handle the node, e.g., print it
  std::cout << node << " ";
  visited[node] = true;
  // for each neighbor
  for (auto& neighbor : graph[node]) {
    if (!visited[neighbor.first]) { DFSVisit(graph, neighbor.first, visited); }
  }
}

void BFS(std::unordered_map<int, std::unordered_map<int, int>>& graph,
         std::vector<int>& start_nodes) {
  std::queue<int> q;
  std::vector<bool> visited(graph.size(), false);
  for (auto node : start_nodes) {
    q.push(node);
    visited[node] = true;
  }
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    // handle the node, e.g., print it
    std::cout << front << " ";
    // for each neighbor
    for (auto& neighbor : graph[front]) {
      if (!visited[neighbor.first]) {
        q.push(neighbor.first);
        visited[neighbor.first] = true;
      }
    }
  }
}

int main() {
  // to make sure that we can get correct graph size by graph.size()
  std::unordered_map<int, std::unordered_map<int, int>> graph = {
      {1, std::unordered_map<int, int>()}, {2, std::unordered_map<int, int>()},
      {3, std::unordered_map<int, int>()}, {4, std::unordered_map<int, int>()},
      {5, std::unordered_map<int, int>()}, {6, std::unordered_map<int, int>()},
      {7, std::unordered_map<int, int>()}, {8, std::unordered_map<int, int>()},
      {9, std::unordered_map<int, int>()}, {10, std::unordered_map<int, int>()}};

  Connect(graph, 1, 2, 1);
  Connect(graph, 2, 3, 1);
  Connect(graph, 3, 4, 1);
  Connect(graph, 4, 5, 1);
  Connect(graph, 5, 1, 1);
  Connect(graph, 6, 7, 1);
  Connect(graph, 6, 9, 1);
  Connect(graph, 7, 9, 1);
  Connect(graph, 8, 6, 1);
  Connect(graph, 8, 10, 1);
  Connect(graph, 9, 10, 1);

  std::vector<int> start_nodes = {1, 8};
  // DFS: 1 5 4 3 2 8 10 9 7 6
  std::cout << "DFS: ";
  DFS(graph, start_nodes);
  std::cout << std::endl;
  // BFS: 1 8 5 2 10 6 4 3 9 7
  std::cout << "BFS: ";
  BFS(graph, start_nodes);
  std::cout << std::endl;

  return 0;
}
