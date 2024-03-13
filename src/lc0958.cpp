#include <queue>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

bool isCompleteTree(TreeNode* root) {
  if (!root) { return true; }
  std::queue<TreeNode*> q;
  q.push(root);
  bool null_seen = false;
  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    // check if we encounter a null node
    if (!curr) {
      null_seen = true;
    } else {
      // a non-null node is seen after a null node
      if (null_seen) { return false; }
      q.push(curr->left);
      q.push(curr->right);
    }
  }
  return true;
}
