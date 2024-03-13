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
  std::vector<Edge*> in_edges_;
  std::vector<Edge*> out_edges_;
};

class Edge {
 public:
  Edge(Node* src, Node* dst) : src_(src), dst_(dst) {}

  Node* src_;
  Node* dst_;
};

class Graph {
 public:
  Graph() = default;

  void DFSRecursive(std::vector<Node*>& start_nodes);
  void DFSVisit(Node* node, std::unordered_set<Node*>& visited);
  void DFSIterative(std::vector<Node*>& start_nodes);
  void BFS(std::vector<Node*>& start_nodes);

  bool IsCyclicWithoutPruining();
  bool DetectCycleFromNodeWithoutPruining(Node* node, std::unordered_set<Node*>& path);
  bool IsCyclic();
  bool DetectCycleFromNode(Node* node, std::unordered_set<Node*>& path,
                           std::unordered_set<Node*>& visited);

  std::vector<Node*> SourceNodes();
  std::vector<Node*> SinkNodes();

  void Connect(Node* src, Node* dst);

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
  for (auto edge : node->out_edges_) {
    Node* dst = edge->dst_;
    if (visited.find(dst) == visited.end()) { DFSVisit(dst, visited); }
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
    for (auto edge : top->out_edges_) {
      if (visited.find(edge->dst_) == visited.end()) {
        stk.push(edge->dst_);
        visited.insert(edge->dst_);
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
    for (auto edge : front->out_edges_) {
      if (visited.find(edge->dst_) == visited.end()) {
        q.push(edge->dst_);
        visited.insert(edge->dst_);
      }
    }
  }
}

bool Graph::IsCyclicWithoutPruining() {
  std::unordered_set<Node*> path;
  for (auto node : nodes_) {
    if (DetectCycleFromNodeWithoutPruining(node, path)) { return true; }
  }
  return false;
}

bool Graph::DetectCycleFromNodeWithoutPruining(Node* node, std::unordered_set<Node*>& path) {
  // base case - null node
  if (!node) { return false; }
  // base case - cycle detected
  if (path.find(node) != path.end()) { return true; }
  path.insert(node);
  for (auto edge : node->out_edges_) {
    if (DetectCycleFromNodeWithoutPruining(edge->dst_, path)) { return true; }
  }
  path.erase(node);
  return false;
}

bool Graph::IsCyclic() {
  std::unordered_set<Node*> path;
  // nodes that have been explored and not in any cycle
  std::unordered_set<Node*> visited;
  for (auto node : nodes_) {
    if (DetectCycleFromNode(node, path, visited)) { return true; }
  }
  return false;
}

bool Graph::DetectCycleFromNode(Node* node, std::unordered_set<Node*>& path,
                                std::unordered_set<Node*>& visited) {
  // base case - null node
  if (!node) { return false; }
  // base case - cycle detected
  if (path.find(node) != path.end()) { return true; }
  // pruning - visited node
  if (visited.find(node) != visited.end()) { return false; }
  path.insert(node);
  visited.insert(node);
  for (auto edge : node->out_edges_) {
    if (DetectCycleFromNode(edge->dst_, path, visited)) { return true; }
  }
  path.erase(node);
  return false;
}

std::vector<Node*> Graph::SourceNodes() {
  std::vector<Node*> srcs;
  for (auto node : nodes_) {
    if (node->in_edges_.empty()) { srcs.push_back(node); }
  }
  return srcs;
}

std::vector<Node*> Graph::SinkNodes() {
  std::vector<Node*> sinks;
  for (auto node : nodes_) {
    if (node->out_edges_.empty()) { sinks.push_back(node); }
  }
  return sinks;
}

void Graph::Connect(Node* src, Node* dst) {
  Edge* edge = new Edge(src, dst);
  src->out_edges_.push_back(edge);
  dst->in_edges_.push_back(edge);
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
  start_nodes.push_back(node8);
  // DFS Recursive: 1 2 3 4 5 8 6 7 9 10
  std::cout << "DFS Recursive: ";
  g.DFSRecursive(start_nodes);
  std::cout << std::endl;
  // DFS Iterative: 8 10 6 9 7 1 2 3 4 5
  std::cout << "DFS Iterative: ";
  g.DFSIterative(start_nodes);
  std::cout << std::endl;
  // BFS: 1 8 2 6 10 3 7 9 4 5
  std::cout << "BFS: ";
  g.BFS(start_nodes);
  std::cout << std::endl;

  // IsCyclicWithoutPruning: True
  std::cout << "IsCyclic: ";
  if (g.IsCyclicWithoutPruining()) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }

  // IsCyclic: True
  std::cout << "IsCyclic: ";
  if (g.IsCyclic()) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }

  // Source Nodes: 8
  std::vector<Node*> srcs = g.SourceNodes();
  std::cout << "Source Nodes: ";
  for (auto src : srcs) { std::cout << src->val << " "; }
  std::cout << std::endl;

  // Sink Nodes: 10
  std::vector<Node*> sinks = g.SinkNodes();
  std::cout << "Sink Nodes: ";
  for (auto sink : sinks) { std::cout << sink->val << " "; }
  std::cout << std::endl;

  return 0;
}
