#include <vector>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

int rob(TreeNode* root) {
  std::pair<int, int> result = RobTree(root);
  return std::max(result.first, result.second);
}

std::pair<int, int> RobTree(TreeNode* node) {
  if (!node) { return std::make_pair(0, 0); }
  auto left = RobTree(node->left);
  auto right = RobTree(node->right);
  // if we rob this node, we cannot rob its children
  int rob_curr = node->val + left.second + right.second;
  // if we do not rob this node, we take the maximum of robbing or not robbing its children
  int not_rob_curr = std::max(left.first, left.second) + std::max(right.first, right.second);
  return std::make_pair(rob_curr, not_rob_curr);
}
