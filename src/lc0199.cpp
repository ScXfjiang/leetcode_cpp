#include <vector>
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
std::vector<int> rightSideView(TreeNode* root) {
  std::vector<int> view;
  rightViewDFS(root, 0, view);
  return view;
}

void rightViewDFS(TreeNode* node, int level, std::vector<int>& view) {
  if (!node) { return; }
  // first time we've reached this level
  if (level == view.size()) { view.push_back(node->val); }
  // prioritize right subtree, then left subtree.
  rightViewDFS(node->right, level + 1, view);
  rightViewDFS(node->left, level + 1, view);
}

// Solution 2: Iterative
std::vector<int> rightSideView(TreeNode* root) {
  if (!root) { return; };
  std::vector<int> view;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int level_size = q.size();
    for (int i = 0; i < level_size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      if (i == level_size - 1) { view.push_back(node->val); }
      if (node->left) { q.push(node->left); }
      if (node->right) { q.push(node->right); }
    }
  }
  return view;
}
