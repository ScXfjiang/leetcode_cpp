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

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
  std::vector<std::vector<int>> result;
  if (!root) { return result; }
  std::queue<TreeNode*> q;
  q.push(root);
  bool l2r = true;
  while (!q.empty()) {
    int level_size = q.size();
    std::vector<int> cur_level(level_size);
    for (int i = 0; i < level_size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      int idx = (l2r) ? i : (level_size - 1 - i);
      cur_level[idx] = node->val;
      if (node->left) { q.push(node->left); }
      if (node->right) { q.push(node->right); }
    }
    l2r = !l2r;
    result.push_back(cur_level);
  }
  return result;
}
