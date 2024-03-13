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

// Solution 1 - Recursion
int minDepth(TreeNode* root) {
  if (!root) { return 0; }
  if (!root->left && !root->right) { return 1; }
  if (root->left && root->right) {
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
  }
  if (!root->left) { return 1 + minDepth(root->right); }
  if (!root->right) { return 1 + minDepth(root->left); }
  return -1;
}

// Solution 2 - Level-order Traversal
int minDepth(TreeNode* root) {
  if (!root) { return 0; }
  std::queue<std::pair<TreeNode*, int>> q;
  q.push({root, 1});
  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();
    if (!node->left && !node->right) { return depth; }
    if (node->left) { q.push({node->left, depth + 1}); }
    if (node->right) { q.push({node->right, depth + 1}); }
  }
  return -1;
}