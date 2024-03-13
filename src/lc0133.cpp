#include <vector>
#include <unordered_map>
#include <queue>

class Node {
 public:
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }

  int val;
  std::vector<Node*> neighbors;
};

// Solution 1: BFS
Node* cloneGraph(Node* node) {
  if (!node) { return nullptr; }
  std::queue<Node*> q;
  std::unordered_map<Node*, Node*> origin2copy;
  q.push(node);
  // shallow copy
  origin2copy[node] = new Node(node->val);
  while (!q.empty()) {
    Node* front = q.front();
    q.pop();
    for (auto& neighbor : front->neighbors) {
      if (origin2copy.find(neighbor) == origin2copy.end()) {
        origin2copy[neighbor] = new Node(neighbor->val);
        q.push(neighbor);
      }
      // deep copy can only be done after all its neighbors are traversed
      origin2copy[front]->neighbors.push_back(origin2copy[neighbor]);
    }
  }
  return origin2copy[node];
}

// Solution 2: DFS
Node* cloneGraph(Node* node) {
  std::unordered_map<Node*, Node*> origin2copy;
  return cloneGraph(node, origin2copy);
}

Node* cloneGraph(Node* node, std::unordered_map<Node*, Node*>& origin2copy) {
  if (!node) { return nullptr; }
  if (origin2copy.find(node) == origin2copy.end()) {
    // shallow copy
    origin2copy[node] = new Node(node->val);
    for (auto& neighbor : node->neighbors) {
      // deep copy can only be done after all its neighbors are traversed
      origin2copy[node]->neighbors.push_back(cloneGraph(neighbor, origin2copy));
    }
  }
  return origin2copy[node];
}

// Solution 3: DFS with static variable
Node* cloneGraph(Node* node) {
  if (!node) { return nullptr; }
  static std::unordered_map<Node*, Node*> origin2copy;
  if (origin2copy.find(node) == origin2copy.end()) {
    // shallow copy
    origin2copy[node] = new Node(node->val);
    for (auto& neighbor : node->neighbors) {
      // deep copy can only be done after all its neighbors are traversed
      origin2copy[node]->neighbors.push_back(cloneGraph(neighbor));
    }
  }
  return origin2copy[node];
}
