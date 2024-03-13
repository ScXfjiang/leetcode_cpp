#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>

class Edge;

class Node {
 public:
  Node(int val) : val(val) {}

  int val;
  std::vector<Edge*> edges_;
};

class Edge {
 public:
  Edge(Node* x, Node* y) : x_(x), y_(y) {}

  Node* x_;
  Node* y_;
};

class Graph {
 public:
  Graph() = default;

  void DFSRecursive(std::vector<Node*>& start_nodes);
  void DFSVisit(Node* node, std::unordered_set<Node*>& visited);
  void DFSIterative(std::vector<Node*>& start_nodes);
  void BFS(std::vector<Node*>& start_nodes);

  void Connect(Node* x, Node* y);

  std::vector<Node*> nodes_;
  std::vector<Edge*> edges_;
};

void Graph::DFSRecursive(std::vector<Node*>& start_nodes) {
  // we can guarantee visited vector is always up to date because it is passed by reference
  std::unordered_set<Node*> visited;
  for (auto node : start_nodes) {
    if (visited.find(node) == visited.end()) { DFSVisit(node, visited); }
  }
}

void Graph::DFSVisit(Node* node, std::unordered_set<Node*>& visited) {
  if (!node) { return; }
  // handle the node, e.g., print it
  std::cout << node->val << " ";
  visited.insert(node);
  // for each neighbor
  for (auto edge : node->edges_) {
    Node* neighbor = edge->x_ == node ? edge->y_ : edge->x_;
    if (visited.find(neighbor) == visited.end()) { DFSVisit(neighbor, visited); }
  }
}

void Graph::DFSIterative(std::vector<Node*>& start_nodes) {
  std::stack<Node*> stk;
  std::unordered_set<Node*> visited;
  for (auto node : start_nodes) {
    stk.push(node);
    visited.insert(node);
  }
  while (!stk.empty()) {
    Node* top = stk.top();
    stk.pop();
    // handle the node, e.g., print it
    std::cout << top->val << " ";
    // for each neighbor
    for (auto edge : top->edges_) {
      Node* neighbor = edge->x_ == top ? edge->y_ : edge->x_;
      if (visited.find(neighbor) == visited.end()) {
        stk.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }
}

void Graph::BFS(std::vector<Node*>& start_nodes) {
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
    std::cout << front->val << " ";
    // for each neighbor
    for (auto edge : front->edges_) {
      Node* neighbor = edge->x_ == front ? edge->y_ : edge->x_;
      if (visited.find(neighbor) == visited.end()) {
        q.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }
}

void Graph::Connect(Node* x, Node* y) {
  Edge* edge = new Edge(x, y);
  x->edges_.push_back(edge);
  y->edges_.push_back(edge);
  edges_.push_back(edge);
}

int main() {
  Graph g;

  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  Node* node8 = new Node(8);
  Node* node9 = new Node(9);
  Node* node10 = new Node(10);

  g.nodes_.push_back(node1);
  g.nodes_.push_back(node2);
  g.nodes_.push_back(node3);
  g.nodes_.push_back(node4);
  g.nodes_.push_back(node5);
  g.nodes_.push_back(node6);
  g.nodes_.push_back(node7);
  g.nodes_.push_back(node8);
  g.nodes_.push_back(node9);
  g.nodes_.push_back(node10);

  g.Connect(node1, node2);
  g.Connect(node2, node3);
  g.Connect(node3, node4);
  g.Connect(node4, node5);
  g.Connect(node5, node1);
  g.Connect(node6, node7);
  g.Connect(node6, node9);
  g.Connect(node7, node9);
  g.Connect(node8, node6);
  g.Connect(node8, node10);
  g.Connect(node9, node10);

  std::vector<Node*> start_nodes;
  start_nodes.push_back(node1);
  start_nodes.push_back(node6);
  // DFS Recursive: 1 2 3 4 5 6 7 9 10 8
  std::cout << "DFS Recursive: ";
  g.DFSRecursive(start_nodes);
  std::cout << std::endl;
  // DFS Iterative : 6 8 10 9 7 1 5 4 3 2
  std::cout << "DFS Iterative : ";
  g.DFSIterative(start_nodes);
  std::cout << std::endl;
  // BFS: 1 6 2 5 7 9 8 3 4 10
  std::cout << "BFS: ";
  g.BFS(start_nodes);
  std::cout << std::endl;

  return 0;
}
