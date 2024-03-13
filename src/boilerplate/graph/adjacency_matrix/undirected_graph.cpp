#include <iostream>
#include <vector>
#include <queue>

// weight = 0 means no edge
// o.w., weight is always positive
void Connect(std::vector<std::vector<int>>& graph, int x, int y, int w) {
  graph[x][y] = w;
  graph[y][x] = w;
}

void DFSVisit(std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited);

void DFS(std::vector<std::vector<int>>& graph, std::vector<int>& start_nodes) {
  // we can guarantee visited vector is always up to date because it is passed by reference
  std::vector<bool> visited(graph.size(), false);
  for (auto node : start_nodes) {
    if (!visited[node]) { DFSVisit(graph, node, visited); }
  }
}

void DFSVisit(std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited) {
  // handle the node, e.g., print it
  std::cout << node + 1 << " ";
  visited[node] = true;
  // for each neighbor
  for (int i = 0; i < graph.size(); ++i) {
    if (graph[node][i] != 0 && !visited[i]) { DFSVisit(graph, i, visited); }
  }
}

void BFS(std::vector<std::vector<int>>& graph, std::vector<int>& start_nodes) {
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
    std::cout << front + 1 << " ";
    // for each neighbor
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[front][i] != 0 && !visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  std::vector<std::vector<int>> graph(10, std::vector<int>(10, 0));

  Connect(graph, 0, 1, 1);
  Connect(graph, 1, 2, 1);
  Connect(graph, 2, 3, 1);
  Connect(graph, 3, 4, 1);
  Connect(graph, 4, 0, 1);
  Connect(graph, 5, 6, 1);
  Connect(graph, 5, 8, 1);
  Connect(graph, 6, 8, 1);
  Connect(graph, 7, 5, 1);
  Connect(graph, 7, 9, 1);
  Connect(graph, 8, 9, 1);

  std::vector<int> start_nodes = {0, 7};
  // DFS: 1 2 3 4 5 8 6 7 9 10
  std::cout << "DFS: ";
  DFS(graph, start_nodes);
  std::cout << std::endl;
  // BFS: 1 8 2 6 10 3 7 9 4 5
  std::cout << "BFS: ";
  BFS(graph, start_nodes);
  std::cout << std::endl;

  return 0;
}
