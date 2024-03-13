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

// Solution 1: Recursive, child of leaf node as base case
int maxDepth(TreeNode* root) {
  // base case: child of leaf node
  if (!root) { return 0; }
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Solution 2: Recursive, leaf node as base case
int maxDepth(TreeNode* root) {
  // edge case, not base case
  if (!root) { return 0; }
  // base case: leaf node
  if (!root->left && !root->right) { return 1; }
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Solution 3: Iterative
int maxDepth(TreeNode* root) {
  if (!root) { return 0; }
  std::queue<TreeNode*> q;
  q.push(root);
  int level = 0;
  while (!q.empty()) {
    int level_size = q.size();
    for (int i = 0; i < level_size; ++i) {
      TreeNode* curr = q.front();
      q.pop();
      if (curr->left) { q.push(curr->left); }
      if (curr->right) { q.push(curr->right); }
    }
    level++;
  }
  return level;
}
