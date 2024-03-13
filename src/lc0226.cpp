#include <algorithm>
#include <queue>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1: Recursive
TreeNode* invertTree(TreeNode* root) {
  // base case: child of leaf node
  if (!root) { return root; }
  std::swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

// Solution 2: Iterative
TreeNode* invertTree(TreeNode* root) {
  if (!root) { return nullptr; }
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* front = q.front();
    q.pop();
    std::swap(front->left, front->right);
    if (front->left) { q.push(front->left); }
    if (front->right) { q.push(front->right); }
  }
  return root;
}