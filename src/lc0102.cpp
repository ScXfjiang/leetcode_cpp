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

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> result;
  if (!root) { return result; }
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int level_size = q.size();
    std::vector<int> curr_level;
    for (int i = 0; i < level_size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      curr_level.push_back(node->val);
      if (node->left) { q.push(node->left); }
      if (node->right) { q.push(node->right); }
    }
    result.push_back(curr_level);
  }
  return result;
}
