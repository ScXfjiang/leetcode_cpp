#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Node {
 public:
  Node() = default;
  Node(int val) : val_(val) {}

  int val_;
  std::vector<Node*> neighbors;
};

void Connect(Node* src, Node* dst) { src->neighbors.push_back(dst); }

void DFSVisit(Node* node, std::unordered_set<Node*>& visited);

void DFS(std::vector<Node*>& start_nodes) {
  // we can guarantee visited vector is always up to date because it is passed by reference
  std::unordered_set<Node*> visited;
  for (auto node : start_nodes) {
    if (visited.find(node) == visited.end()) { DFSVisit(node, visited); }
  }
}

void DFSVisit(Node* node, std::unordered_set<Node*>& visited) {
  if (!node) { return; }
  // handle the node, e.g., print it
  std::cout << node->val_ << " ";
  visited.insert(node);
  // for each neighbor
  for (Node* neighbor : node->neighbors) {
    if (visited.find(neighbor) == visited.end()) { DFSVisit(neighbor, visited); }
  }
}

void BFS(std::vector<Node*>& start_nodes) {
  std::queue<Node*> q;
  std::unordered_set<Node*> visited;
  for (auto node : start_nodes) {
    q.push(node);
    visited.insert(node);
  }
  while (!q.empty()) {
    Node* front = q.front();
    q.pop();
    // handle the node, e.g., print it
    std::cout << front->val_ << " ";
    // for each neighbor
    for (Node* neighbor : front->neighbors) {
      if (visited.find(neighbor) == visited.end()) {
        q.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }
}

bool DetectCycleFromNode(Node* node, std::unordered_set<Node*>& path,
                         std::unordered_set<Node*>& visited);

bool IsAcyclic(std::vector<Node*>& graph) {
  std::unordered_set<Node*> path;
  // nodes that have been explored and not in any cycle
  std::unordered_set<Node*> visited;
  for (Node* node : graph) {
    if (DetectCycleFromNode(node, path, visited)) { return true; }
  }
  return false;
}

bool DetectCycleFromNode(Node* node, std::unordered_set<Node*>& path,
                         std::unordered_set<Node*>& visited) {
  // edge case - null node
  if (!node) { return false; }
  // base case - cycle detected
  if (path.find(node) != path.end()) { return true; }
  // pruning - visited node
  if (visited.find(node) != visited.end()) { return false; }
  path.insert(node);
  visited.insert(node);
  for (Node* neighbor : node->neighbors) {
    if (DetectCycleFromNode(neighbor, visited, path)) { return true; }
  }
  path.erase(node);
  return false;
}

int main() {
  std::vector<Node*> graph;
  for (int i = 1; i <= 10; ++i) { graph.push_back(new Node(i)); }
  Connect(graph[0], graph[1]);
  Connect(graph[1], graph[2]);
  Connect(graph[2], graph[3]);
  Connect(graph[3], graph[4]);
  Connect(graph[4], graph[0]);
  Connect(graph[5], graph[6]);
  Connect(graph[5], graph[8]);
  Connect(graph[6], graph[8]);
  Connect(graph[7], graph[5]);
  Connect(graph[7], graph[9]);
  Connect(graph[8], graph[9]);

  std::vector<Node*> start_nodes;
  start_nodes.push_back(graph[0]);
  start_nodes.push_back(graph[7]);
  // DFS: 1 2 3 4 5 8 6 7 9 10
  std::cout << "DFS: ";
  DFS(start_nodes);
  std::cout << std::endl;
  // BFS: 1 8 2 6 10 3 7 9 4 5
  std::cout << "BFS: ";
  BFS(start_nodes);
  std::cout << std::endl;

  // IsAcyclic: True
  std::cout << "IsAcyclic: ";
  if (IsAcyclic(graph)) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }

  return 0;
}
