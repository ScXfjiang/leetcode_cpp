#include <queue>

struct Node {
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}

  int val;
  Node* left;
  Node* right;
  Node* next;
};

Node* connect(Node* root) {
  if (!root) { return root; }
  std::queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    Node* prev = nullptr;
    int level_size = q.size();
    for (int i = 0; i < level_size; ++i) {
      Node* curr = q.front();
      q.pop();
      if (prev) { prev->next = curr; }
      prev = curr;
      if (curr->left) { q.push(curr->left); }
      if (curr->right) { q.push(curr->right); }
    }
    prev->next = nullptr;
  }
  return root;
}