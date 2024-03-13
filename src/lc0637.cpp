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

std::vector<double> averageOfLevels(TreeNode* root) {
  std::vector<double> avg_level;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int level_size = q.size();
    double level_sum = 0;
    for (int i = 0; i < level_size; ++i) {
      TreeNode* curr = q.front();
      q.pop();
      level_sum += curr->val;
      if (curr->left) { q.push(curr->left); }
      if (curr->right) { q.push(curr->right); }
    }
    avg_level.push_back(level_sum / level_size);
  }
  return avg_level;
}
